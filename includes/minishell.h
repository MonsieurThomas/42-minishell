/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 11:10:16 by yviavant          #+#    #+#             */
/*   Updated: 2022/07/22 20:57:18 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include "../libft/libft.h"
# include <sys/types.h>
# include <signal.h>
# include <sys/wait.h>
# include <termios.h>
# include <dirent.h>
# include <math.h>
# include <fcntl.h>

typedef struct s_glob
{
	pid_t				pid;
	int					status;
	int					ret_value;
}						t_glob;

typedef struct s_data
{
	char				**env;
	char				**old_env;
	char				**export;

	char				**tab_exec;
	int					tab_exec_entered;
	char				c;
	int					i;
	int					is_touching;
	char				*contents;

	int					dl;
	int					lguill_i;
	int					lguill_j;
	char				*lguill_tmp;

	int					cont0_is_var;
	int					is_in_env;
	int					is_entered;
	int					is_cursed;
	int					is_cursed1;
	int					is_cursed2;
	int					ii;
	int					j;
	int					k;
	char				*tmp;
	char				*new_s;

	int					error;
	int					guill;
	pid_t				pid;
	int					actual_i;
	char				**lexer;
	int					*lexer_type;
	int					token_count;
	char				*read_line;
	int					isdollar;

	int					echo_n;
	int					is_builtin;
	int					error_nb;
	pid_t				error_nb_pid;
	int					error_quote;

	char				**args;
	char				*path;
	char				**env2;

}						t_data;

void		rl_replace_line(const char *text, int clear_undo);
void		init_lexer(char *contents, t_data *lexer);
void		lexer_advance(t_data *lexer);
void		lexer_skip_whitespace(t_data *lexer);
char		*lexer_get_next_token(t_data *lexer);
char		*lexer_collect_string(t_data *lexer, char guill);
char		*lexer_collect_id(t_data *lexer);
char		*lexer_get_current_char_as_string(char c, t_data *lexer);
void		count_token(t_data *lexer);
void		init_lexer(char *contents, t_data *lexer);
void		lexer_collect_string_count(t_data *lexer);
void		lexer_collect_id_count(t_data *lexer);
char		*ft_special_char(char c, t_data *lexer);
void		lexer_main(t_data *data);
char		*ft_isdollar(char *s, t_data *data);
char		*ft_no_variable(t_data *data, char *s);
char		*ft_is_variable(char *s, t_data *data);
char		*ft_is_variable_2nd(char *s, t_data *data);
int			count_quotes(t_data *data);
int			ft_export_only(t_data *data);
void		ft_free_export(char **env);
char		*ft_remove_guill(char *s);
char		*ft_check_guill(char *s);
char		*export_add_guill(char *str);
char		*ft_is_variable_2nd(char *s, t_data *data);
char		*ft_is_variable(char *s, t_data *data);
char		*ft_no_variable(t_data *data, char *s);
int			count_quotes(t_data *data);
void		spec(t_data *data);
char		*ft_isdollar_string(char *s, t_data *data, char guill);

int			is_unexepted_token(t_data *data);
int			is_special(t_data *data);
char		*readline(const char *prompt);
void		ft_echo(t_data *data);
void		ft_export(t_data *data);
void		ft_pwd(t_data *data);
void		ft_unset(t_data *data);
void		ft_exit(t_data *data);
void		ft_cd(t_data *data);
void		init_env_and_value(char **env, t_data *data);
char		*get_env(t_data *data, char *str);
void		ft_env(t_data *data);
void		ft_free_simple_tab(char **tab);
void		add_to_export_tab(t_data *data, char *tmp);
void		add_to_export(t_data *data, int j);
int			ft_check_existence_export_export(t_data *data, int j);
void		ft_export_export(t_data *data, int i, int j);
void		add_to_export_secret(t_data *data, int i, int j);
int			export_2nd_part(t_data *data, int i, int j);
void		ft_export(t_data *data);
int			ft_check_existence_for_env(t_data *data, int i, int j);
char		*ft_is_quote(t_data *data, int j);
void		ft_add_to_env(t_data *data, int j);
int			is_lexer_cursed(t_data *data, int j);

void		ft_exec_main(t_data *data);
void		int_ft(int sig);
void		show_ctl(int b);
void		ft_free(t_data *data);
void		ft_free_simple_tab(char **tab);

#endif
