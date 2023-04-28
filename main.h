#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>

extern char **environ;
char *strjoin(char *, char *);
int check_space(char *);
char *path_searcher(char *, char *);
int strcheck(char *str, char *ch);
int command_checker(char *);
void error_print(char *, char *, int);
char **env(char **envp);
char *buff_cleaner(char *, ssize_t);
char **tokenizer(char **, char *, char *);
int str_chk(char *str1, char *str2);
char *gete(char *str);
char *split_str(char *str);
char * _getenv(char *str);
void exit1(int num);
char *str_cpy(char *);
int str_cnp(char *str1, char *str2);
void join(char *env, int len, char sym, char *name, char *val);
int _strlen(char *str);
char *getenv2(char *);
void cleaner(char **envp, char **argv);
char *_set(char *name, char *value, char *env_var);
void free_func(char *buffer, char **envp);
char *_memcpy(char *);
#endif
