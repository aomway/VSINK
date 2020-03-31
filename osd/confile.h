#ifndef __CONFILE_H__
#define __CONFILE_H__

typedef struct item_t {
    char *key;
    char *value;
}ITEM;

int confile_init(void);
void confile_exit(void);
int parse_confile(const char *file);
int save_confile(const char *file);
char* get_conf_string(const char *key, char *default_value);
int get_conf_int(const char *key, int default_value);
float get_conf_float(const char *key, float default_value);
int set_conf_string(const char *key, char *value);
int set_conf_int(const char *key, int value);
int set_conf_float(const char *key, float value);

#endif
