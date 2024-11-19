NAME	= test
CXXFLAG = -Wall -Wextra -Werror -std=c++98
CXX		= c++

SRCS 								=	main \
										Bureaucrat \
										Form

SRC_CUR	= $(addsuffix .cpp, $(SRCS))
OBJ		= $(SRC_CUR:.cpp=.o)
HEAD	= Bureaucrat.hpp Form.hpp

all : $(NAME)

$(NAME) : $(OBJ) $(HEAD)
	$(CXX) $(CXXFLAG) $(OBJ) -o $(NAME)

.cpp.o : $(HEAD)
	$(CXX) $(CXXFLAG) -c -o $@ $<

clean : 
	@rm -rf *.o

fclean : clean
	@rm -rf $(NAME)

re	:
	@$(MAKE) fclean
	@clear
	@$(MAKE) all

.PHONY : all
