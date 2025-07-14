OS = $(shell uname)
CPU = $(shell uname -m)

# nom de l'executable
NAME = philo

# Source and object diretories
SRCDIR = src
OBJDIR = obj

# ifeq ($(OS), Darwin)
# 	ifeq ($(CPU), arm64)
		
# 	else
		
# 	endif
# else ifeq ($(OS), Linux)
	
# endif

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror
DEBUG_FLAGS = -g3 -fno-omit-frame-pointer -fstack-protector-all

ifeq ($(OS), Darwin)
	ifeq ($(CPU), arm64)
		INCLUDES = -I includes
	else
		INCLUDES = -I includes
	endif
else ifeq ($(OS), Linux)
	INCLUDES = -I includes
endif

RM = rm -f

vpath %.c \
	$(SRCDIR) \
	$(SRCDIR)/utils \
	$(SRCDIR)/parsing \
	$(SRCDIR)/includes \
	$(SRCDIR)/philo_routine \
	$(SRCDIR)/thread_checker \
	$(SRCDIR)/threads_and_mutex \
	$(SRCDIR)/utils/init_program \
	$(SRCDIR)/utils/function_utils \
	$(SRCDIR)/utils/error_free_exit \

# Sources and object files
# attention supprimer le testing.c
SRC = main.c \
init.c \
string_utils.c convert_utils.c \
free.c \
thread_checker_init.c \
check_entry.c parsing_av.c \
threads_creation.c threads_terminate.c threads_join.c mutex_fork.c\
philo_life.c philo_handler.c time_handler.c\

OBJS = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

all: $(NAME)

debug: CFLAGS = $(DEBUG_FLAGS)
debug: re

# Sanitize
sanitize: DEBUG_FLAGS += -fsanitize=address 
sanitize: debug 

# Rule to compile with Leaks check
leaks:
ifeq ($(OS), Darwin)
    MallocStackLogging=YES leaks --outputGraph=minishell.memgraph --fullContent --fullStackHistory --atExit -- ./$(NAME)
else ifeq ($(OS), Linux)
	valgrind --leak-check=full --log-file=valgrind.log --show-leak-kinds=all --track-fds=all --default-suppressions=yes ./$(NAME)
endif
	
# Compile each .c file to .o		
$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	
$(NAME): $(OBJS)
	@echo "$(GREEN)Compilation de $(NAME)...$(NC)"
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Rule to clean up object files	
clean:
		$(RM) $(OBJS)

#Rule to clean  up object files and the library
fclean: clean
		$(RM) $(NAME)

# Rule to recompile everything
re: fclean all

.PHONY: all clean fclean re debug sanitize