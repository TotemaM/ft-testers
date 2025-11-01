PDIR :=

export MAKEFLAGS=--no-print-directory

.PHONY: check all norm libft

all:
	@ echo "Choose a project and set PDIR variable to the root of the project."

check:
	@if [ -z "$(PDIR)" ]; then \
		echo "Set PDIR var to root of the project" && exit 1; \
	fi

norm:
	@ cd $(PDIR) && ! norminette | grep -v "OK"

libft: check
	@ $(MAKE) -C $(PDIR)
	@ $(MAKE) -C . norm
	@ cc $(shell find libft -type f -name "*.c") $(PDIR)/libft.a -o test -I $(PDIR) -I libft -fsanitize=address,leak,undefined -g
	@ ./test