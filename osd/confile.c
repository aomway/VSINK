#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/file.h>

#define CONF_FILE "/data/decode.cfg"
//#include "config.h"
#include "confile.h"

static ITEM items[1024];// 最大配置项
static int num;//有效配置项

/*
 *去除字符串右端空格
 */
static char *strtrimr(char *pstr)
{
    int i;
    i = strlen(pstr) - 1;
    while (isspace(pstr[i]) && (i >= 0))
        pstr[i--] = '\0';
    return pstr;
}
/*
 *去除字符串左端空格
 */
static char *strtriml(char *pstr)
{
    int i = 0,j;
    j = strlen(pstr) - 1;
    while (isspace(pstr[i]) && (i <= j))
        i++;
    if (0<i)
        strcpy(pstr, &pstr[i]);
    return pstr;
}
/*
 *去除字符串两端空格
 */
static char *strtrim(char *pstr)
{
    char *p;
    p = strtrimr(pstr);
    return strtriml(p);
}

/*
 *从配置文件的一行读出key或value,返回item指针
 *line--从配置文件读出的一行
 */
static int get_item_from_line(char *line, ITEM *item)
{
    char *p = strtrim(line);
    int len = strlen(p);
    if(len <= 0){
        return -1;//空行
    }
    else if(p[0]=='#'){
        return -1;//注释
    }else{
        char *p2 = strchr(p, '=');
		if(p2 == NULL)
			return -1;
        *p2++ = '\0';
        item->key = (char *)malloc(strlen(p) + 1);
        item->value = (char *)malloc(strlen(p2) + 1);
        strcpy(item->key,p);
        strcpy(item->value,p2);
    }
	
	return 0;
}

static int file_to_items(const char *file, ITEM *items, int *num)
{
    char line[1024];
    FILE *fp;
    int fd;
	int ret;

    fp = fopen(file,"r");
    if(fp == NULL)
        return -1;

    fd = fileno(fp);
    ret = flock(fd,LOCK_EX|LOCK_NB);
    while (ret != 0)
    {
	//printf("c:r block\n");
	usleep(100000);
	ret = flock(fd,LOCK_EX|LOCK_NB);
    }
    //printf("sys.cfg was read locked.\n");

    int i = 0;
    while(fgets(line, 1023, fp)){
		ret = get_item_from_line(line, &items[i]);
		if(ret < 0)
			continue;
		i++;
    }
    (*num) = i;

    flock(fd,LOCK_UN);
    fclose(fp);
    return 0;
}

static int add_item(ITEM *item, const char *key, char *value)
{
	item->key = (char *)malloc(strlen(key) + 1);
	item->value = (char *)malloc(strlen(value) + 1);
	strcpy(item->key, key);
	strcpy(item->value, value);
	num++;
	
	return 0;
}

/*
 *读取value
 */
char* get_conf_string(const char *key, char* default_value)
{
	int i;
	char *value;

	//查找要修改的项
	for(i=0;i<num;i++){    
    	if(!strcmp(items[i].key, key)){
			value = items[i].value;
            break;
        }
	}

	if(i>=num){
		printf("item %s not found, using default value %s\n", key, default_value); 
		value = default_value;
		add_item(&items[i], key, value);
	}

	return value;
}

int get_conf_int(const char *key, int default_value)
{
	char *p;
    char value_str[32];

    sprintf(value_str, "%d", default_value);
	p = get_conf_string(key, value_str);

	return atoi(p);
}

float get_conf_float(const char *key, float default_value)
{
    char *p;
    char value_str[32];

    sprintf(value_str, "%f", default_value);
    p = get_conf_string(key, value_str);

    return atof(p);
}

int set_conf_string(const char *key, char *value)
{
    int i;
    //查找要修改的项
    for(i=0;i<num;i++){
        if(!strcmp(items[i].key, key)){
			free(items[i].value);
			items[i].value = (char *)malloc(strlen(value) + 1);
			strcpy(items[i].value, value);
            break;
        }
    }

	if(i>=num){
		printf("item not found,  add item: %s=%s\n", key, value);
		add_item(&items[i], key, value);
	}	

	return 0;
}

int set_conf_int(const char *key, int value)
{
	char value_str[32];
	sprintf(value_str, "%d", value);

	return set_conf_string(key, value_str);
}

int set_conf_float(const char *key, float value)
{
    char value_str[32];
    sprintf(value_str, "%.2f", value);

    return set_conf_string(key, value_str);
}

int save_confile(const char *file)
{
	int i;
    FILE *fp;
    int fd;
    int ret;

    fp = fopen(file, "w");
    if(fp == NULL)
        return -1;

    fd = fileno(fp);
    ret = flock(fd,LOCK_EX|LOCK_NB);
    while (ret != 0)
    {
	//printf("c:w block\n");
        usleep(100000);
        ret = flock(fd,LOCK_EX|LOCK_NB);
    }
    //printf("sys.cfg was write locked.\n");

    for(i=0; i<num; i++){
        fprintf(fp,"%s=%s\n",items[i].key, items[i].value);
        //printf("%s=%s\n",items[i].key, items[i].value);
    }
    //flock(fd,LOCK_UN);
    fflush(fp);
    fsync(fd);
    flock(fd,LOCK_UN);
    fclose(fp);

    return 0;

}

int parse_confile(const char *file)
{
	return file_to_items(file, items, &num);
}

int confile_init(void)
{
	return parse_confile(CONF_FILE);
}

void confile_exit(void)
{
    int i;

    for(i=0;i<num;i++) {
        if(items[i].key)
            free(items[i].key);
        if(items[i].value)
            free(items[i].value);
    }

    num = 0;
}
