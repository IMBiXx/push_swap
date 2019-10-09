/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 19:08:22 by tpotier           #+#    #+#             */
/*   Updated: 2019/08/06 15:43:05 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <inttypes.h>

# define GNL_BS		32
# define FLAG_SH	(1 << _FLAG_SH)
# define FLAG_0		(1 << _FLAG_0)
# define FLAG_M		(1 << _FLAG_M)
# define FLAG_P		(1 << _FLAG_P)
# define FLAG_SP		(1 << _FLAG_SP)

# define CONV_CHARS	"cspdDioOuUxXfkKbBr"
# define FLAG_CHARS	"#0-+ "
# define MOD_CHARS	"lhLjz"
# define DIGITS		"0123456789"
# define VALID_CHRS	(FLAG_CHARS MOD_CHARS DIGITS ".*")

# define K_COL_MSK	0xffffffUL

# define K_M_BOLD	(1UL << 48)
# define K_M_NBOLD	(1UL << 49)
# define K_M_ITAL	(1UL << 50)
# define K_M_NITAL	(1UL << 51)
# define K_M_UNDER	(1UL << 52)
# define K_M_NUNDER	(1UL << 53)

# define K_BLACK	0x000000UL
# define K_RED		0xff0000UL
# define K_GREEN	0x00ff00UL
# define K_YELLOW	0xffff00UL
# define K_BLUE		0x0000ffUL
# define K_PURPLE	0xff00ffUL
# define K_CYAN		0x00ffffUL
# define K_WHITE	0xffffffUL

# define K_BG_SHIFT	24

# define INFP		(1.0 / 0.0)
# define INFN		(-1.0 / 0.0)

enum				e_flags
{
	_FLAG_SH = 0,
	_FLAG_0,
	_FLAG_M,
	_FLAG_P,
	_FLAG_SP
};

typedef enum		e_mods
{
	MOD_HH = 0,
	MOD_H,
	MOD_NONE,
	MOD_L,
	MOD_LL,
	MOD_LLL,
	MOD_J,
	MOD_Z
}					t_mods;

typedef long		t_style;

typedef struct		s_conv_spec
{
	int				flags;
	unsigned int	field;
	int				precision;
	char			modifier;
	char			type;
	int				size;
}					t_conv_spec;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_inter
{
	long			l;
	long			r;
}					t_inter;

typedef struct		s_dlist
{
	void			*content;
	struct s_dlist	*prev;
	struct s_dlist	*next;
}					t_dlist;

typedef struct		s_sstack
{
	int				*stack;
	size_t			sp;
	size_t			size;
}					t_sstack;

typedef struct		s_fb
{
	char			*buff;
	int				fd;
}					t_fb;

long				ft_map(long n, t_inter in, t_inter out);

int					ft_getnextline(const int fd, char **line);

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *h, const char *n);
char				*ft_strnstr(const char *h, const char *n, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
size_t				ft_nlen_base(long long n, int base);
long long			ft_max(long long a, long long b);
long long			ft_min(long long a, long long b);
long				ft_atoi_len(char *str, size_t *i);
void				ft_putnstr(char *str, size_t len);
void				ft_putnchar(char c, int n);

void				ft_swap(void *a, void *b, size_t s);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
int					ft_strlen_bfrchr(char *s, char c, size_t *size);
int					ft_strncat_mal(char **s1, char *s2, size_t n);

void				ft_putchar_fd(char c, int fd);
void				ft_putchar(char c);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr(int n);
char				*ft_itoa(int n);

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *nw);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				*ft_lstdelif(t_list **alst,
						int (*cond)(void *, size_t, void *),
						void *comp, void (*del)(void *, size_t));

t_dlist				*ft_dlstnew(void *content);
void				ft_dlstdel(t_dlist **lst, void (*del)(void *));
void				ft_dlstadd_end(t_dlist **lst, void *content);
void				ft_dlstdelall(t_dlist **lst, void (*del)(void *));
void				ft_dlstdisp(t_dlist *stk, void (*dsp)(void *));

void				ft_stkswap(t_dlist **stk);
void				ft_stkpush(t_dlist **stk, void *n);
void				*ft_stkpop(t_dlist **stk);

void				ft_sstkswap(t_sstack *stk);
void				ft_sstkpush(t_sstack *stk, int n);
int					ft_sstkpop(t_sstack *stk);
void				ft_sstkrot(t_sstack *stk);
void				ft_sstkrrot(t_sstack *stk);
int					ft_sstkchkord(t_sstack *stk);
void				ft_sstkdisp(t_sstack *stk);
t_sstack			*ft_sstkinit(size_t s);
void				ft_sstkdel(t_sstack **stk);
t_sstack			*ft_sstkcpy(t_sstack *s);

int					ft_printf(const char *format, ...);

int					parse_print_format(char *format, va_list arg);

void				ft_putl_zer_base(long long n, int zer, char f_sgn, int b);
void				ft_putf_zer_base(long double n, int zer, char f_sgn, int b);
void				ft_putl_zer_base_u(unsigned long long n, int zer, int cas,
		int b);

intmax_t			get_arg_int(t_conv_spec *cspec, va_list arg);
long double			get_arg_float(t_conv_spec *cspec, va_list arg);
uintmax_t			get_arg_uint(t_conv_spec *cspec, va_list arg);

void				ft_put_conv_spec(t_conv_spec *cspec, va_list arg, int *c);

int					put_d(t_conv_spec *cs, va_list arg);
int					put_u(t_conv_spec *cs, va_list arg);
int					put_x(t_conv_spec *cs, va_list arg);
int					put_p(t_conv_spec *cs, va_list arg);
int					put_o(t_conv_spec *cs, va_list arg);
int					put_c(t_conv_spec *cs, va_list arg);
int					put_s(t_conv_spec *cs, va_list arg);
int					put_f(t_conv_spec *cs, va_list arg);
int					put_k(t_conv_spec *cs, va_list arg);
int					put_b(t_conv_spec *cs, va_list arg);
int					put_other(t_conv_spec *cs);
int					put_r(t_conv_spec *cs, va_list arg);

void				putstr_r(char *s, unsigned int size);
int					is_neg(long double f);
int					is_special(long double f);

void				parse_flags(t_conv_spec *cs, char *fmt, size_t *i);
void				parse_field(t_conv_spec *cs, char *fmt, size_t *i,
		va_list arg);
void				parse_precision(t_conv_spec *cs, char *fmt, size_t *i,
		va_list arg);
void				parse_modifiers(t_conv_spec *cs, char *fmt, size_t *i);

#endif
