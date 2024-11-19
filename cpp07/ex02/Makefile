NAME	= test
CXXFLAG = -Wall -Wextra -Werror -std=c++98
CXX		= c++

SRCS 								=	main \

SRC_CUR	= $(addsuffix .cpp, $(SRCS))
OBJ		= $(SRC_CUR:.cpp=.o)
HEAD	= Array.hpp

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
	@$(MAKE) all

.PHONY : all
