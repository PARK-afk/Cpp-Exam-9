NAME	= btc
CXXFLAG = -Wall -Wextra -Werror -std=c++98
CXX		= c++

SRCS 								=	main \
										BitcoinExchange

SRC_CUR	= $(addsuffix .cpp, $(SRCS))
OBJ		= $(SRC_CUR:.cpp=.o)
HEAD	= BitcoinExchange.hpp

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
