# Git and Mingw64 tutorrial

[Git Download (Windows)](https://git-scm.com/install/windows) 

Staging Area (file): lastest changes <br>
Commits (folder): saved versions

## Commands for mingw64
Commands starts always with `git`
| command | funktion |
| :--- | :--- |
| `git config --global user.email "`*emailOfGithubAccount*`"` | for login: has to be your github email address |
| `git config --global user.name "`*YourName*`"` | for login: your name |
| `git add `*filename* | tracking opend file, adding it for a new version |
| `git add .` | add all files |
| `git init` | initialization of repository |
| `git clone`*URL* | downloads a special project from the cloud |
| `git status` | shows modified files and current state |
| `git commit -m "`*commitname*`"` | commit with name works also in the source control paddle |
| `git push` | load up to cloud |
| `git pull` | download from cloud and merge with locals |
| `git fetch` | download from cloud, does not overwrite your local files, to see what other people did |
| `git restore `*file* | sets file to the last commit |
| `git diff` | shows you, what you changed since the last commit |
| `git diff --cached` | shows the new things for "check-in" |
| `git log --online` | shows a short list of the last commits |

| command | designation | funktion | 
| :--- | :--- | :--- |
| `ls` | *list* | show content |
| `ls -a` | *list all* | show all files |
| `ls -l` | *list as list* | show all files in a long list with details |
| `ls -la` | *list all long* | combines `ls -a` and `ls -l` |
| `cd `*foldername* | *change directory* | goes to underfolder |
| `cd ..` | *change directory* | goes on layer above |
| `pwd` | *print working directory* | shows you, in which folder you are (shows path) |
| `mkdir `*foldername* | *make directory* | new folder |
| `rmdir `*foldername* | *remove directory* | delete empty folder |
| `rm -r `*foldername* | *remove recursive* | delete folder and files in it |
| `touch `*filename* |  | make a new file e.g. touch main.py | 
| `rm `*filename* | *remove* | delete a file (*.txt would delete all .txt files in this folder) | 
| `cp `*filename*` `*addedpastedpath* | *copy* | copy file and paste it (e.g. `cp main.py backup/main_alt.py`) | 
| `mv `*filename*` `*addedpath* | *move* | moves a file to this added path | 
| `mv `*filename*` `*newfilename* |  | changes the filename of a file | 
| `cat `*filename* | *concatenate* | shows content of the file in the terminal | 
| `head` |  | shows first ten lines from the content of the file | 
| `tail` |  | shows last ten lines from the content of the file | 
| `grep`*searchtext*` `*file* |  | searches a text / word in a file
| `grep -r`*searchtext* |  | searches a text / word in the whole folder
| `diff -u `*filename1*` `*filename2* | *difference* | shows the diference between two files
| `clear` |  | clears the terminal-window |

## Letters right of file name (VSCode):
| Letter | funktion |
| :--- | :--- |
| `U` | unknown, git doesn't know this file |
| `M` | modified |
| `A` | added |
| `D` | deleted |