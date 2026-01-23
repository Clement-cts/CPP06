NAME = real_type

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 

SRCS = srcs/main.cpp srcs/Identify.cpp srcs/Base.cpp

OBJ_DIR = build
OBJS = $(addprefix $(OBJ_DIR)/,$(SRCS:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re