G++			=	g++

CORE_PATH	=	./core
SRCS_PATH	=	./sources
TST_PATH	=	./tests
INCS_PATH	=	./includes

NAME		=	my_convert_temp
TEST_NAME 	= 	test_$(NAME)


INCFLAGS	+=	-I $(INCS_PATH)
#LIBFLAG 	+=	-L

CPPFLAGS	+= -Wall -Wextra -Werror $(INCFLAGS)#-W -std=c++1z


SRCS		=	$(SRCS_PATH)/my_convert_temp.cpp \
				$(CORE_PATH)/main.cpp

SRC_TEST	=	$(TST_PATH)/$(NAME)_test.cpp

OBJS		=	$(SRCS:.cpp=.o)

CLEAN		=	clean
FCLEAN		=	fclean


all			:	$(NAME)

$(NAME)		:	$(OBJS)
				$(G++) $(OBJS) -o $(NAME) $(CPPFLAGS)

RM			=	rm -rf

clean		:
				$(RM) $(OBJS)
				@$(MAKE) $(CLEAN) -C $(TST_PATH)

fclean		:	clean
				$(RM) $(NAME) $(TEST_NAME)
				@$(MAKE) $(FCLEAN) -C $(TST_PATH)

re			: 	fclean all

tests_run	:	fclean
				@$(MAKE) -C $(TST_PATH)
				$(TST_PATH)/$(TEST_NAME)

.PHONY		: 	all clean fclean re tests_run

# $(CC) -o $(TEST_NAME) $(SRC) $(SRC_TEST) $(TESTFLAGS) $(LIBFLAG)
#-L. -lmy_malloct