NAME		=	ClapTrap

CXX			=	clang++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRCS		=	main.cpp \
				ClapTrap.cpp

INC			=	ClapTrap.hpp

OBJS		= 	$(SRCS:.cpp=.o)

all :		$(NAME)

$(NAME)	: $(OBJS) $(INC)
			$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean	:
			rm -f $(OBJS)

fclean	:	clean
			rm -f $(NAME)

re		:	fclean all

.PHONY = all clean fclean re