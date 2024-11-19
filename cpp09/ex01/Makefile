NAME = RPN

CXX = c++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = main.cpp RPN.cpp

OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) -I. $^ -o $@

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -I. -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean
	$(MAKE) all

.PHONY: all clean fclean re bonus