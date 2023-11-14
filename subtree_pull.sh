#!/bin/sh
#first time
#git subtree add --prefix libft https://github.com/kristykawai/libft.git main --squash
git subtree pull --prefix libft https://github.com/kristykawai/libft.git main --squash
git push
