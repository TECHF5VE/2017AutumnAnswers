> 笔记纯属个人理解，并不严谨  
> 仅供参考  
> By LeoB_O
###Git 基本概念及常用命令

#### 1. Git 简介
    - Git 是一个版本控制系统(Version Control System)
    - Git 与其他CVS相比更加高效，使用也更加快捷方便
#### 2. Git 基本概念
![Three Area](https://git-scm.com/book/en/v2/images/areas.png)

+ Git 分为三个区，包括 Git仓库(Git Repository)、工作目录(Working Directory)、暂存区域(Staging Area)
    - Git仓库是保存大部分数据的地方
    - 工作目录是项目的某个版本独立提取出来的内容
    - 暂存区域保存了下次将会提交(commit)的文件列表
+ Git的基本工作流程
    1. 在工作目录中修改(modify)文件
    2. 暂存文件，将文件快照放入暂存区域(add)
    3. 提交(commit)更新，将暂存区文件保存至Git Repository。
#### 3. 建立一个项目仓库
>Git 仓库是一个用来保存各种文件的地方。在我的理解中，仓库与文件夹的概念十分相似。位于仓库中的文件会被Git所“关注”，你可以选择追踪或者不追踪一个文件。被追踪的文件的内容一旦被修改，Git会马上“知道”，并可以采取相应的措施。

**(1). 初始化一个仓库(init)**
 
如果想使用Git对现有项目进行管理，只需要将当前项目所在的文件夹设置为Git仓库即可。在命令行中进入到项目所在目录，输入：

    $ git init


**(2). 克隆一个仓库(clone)**

除了直接新建一个仓库外，还可以选择克隆一个已有的远程Git仓库。输入：

    $ git clone [url] [name]
例如克隆Git的一个可链接库libgit2：

    $ git clone https://github.com/libgit2/libgit2 mylibgit

#### 4.追踪文件

工作目录下的文件状态不外乎两种：`已追踪` 和 `未追踪`。已追踪的文件是指那些被纳入了版本控制的文件。未追踪则表示不需要进行版本控制的文件。如果新建仓库时是通过已有项目新建的，那么新建仓库时项目目录中的所有文件都被纳入追踪的文件，后续添加的文件则需要手动添加追踪。

![Status of file](https://git-scm.com/book/en/v2/images/lifecycle.png)

已追踪的文件继续细分还可以分为：`未修改(Unmodified)`、 `已修改(Modified)` 和 `已缓存(Staged)`。 状态间的转换条件见上图。

+ 查看当前文件状态**(status)**
#
    $ git status
这个命令可以指出当前工作目录下所有文件的状态。

+ 添加跟踪文件**(add)**
#
	$ git add [文件名]
这个命令可以将你想跟踪(track)的文件添加至跟踪目录，以便文件内容发生修改时可以查询。

如果文件已经被添加至追踪目录，那么这个命令可以被用来在文件内容发生改变时将文件保存至缓存区，以便下次`commit`时保存。

+ 忽略不想追踪的文件

如果当前工作目录下存在未跟踪的文件，Git会持续提醒你。如果想忽略这种提醒，可以将不想追踪的文件添加至一个目录里。  
创建一个名为`.gitignore`的文件，在其中列出要忽略的文件的名称的模式(pattern)。 例如：

	$ cat .gitignore
    *.[oa]
    *~
第一行告诉 Git 忽略所有以 .o 或 .a 结尾的文件。一般这类对象文件和存档文件都是编译过程中出现的。 第二行告诉 Git 忽略所有以波浪符（~）结尾的文件，许多文本编辑软件（比如 Emacs）都用这样的文件名保存副本。 此外，你可能还需要忽略 log，tmp 或者 pid 目录，以及自动生成的文档等等。 要养成一开始就设置好 .gitignore 文件的习惯，以免将来误提交这类无用的文件。

#### 5.查看修改
`git status`能粗略地指出文件的状态，如果想知道具体改变了什么地方，可以使用：

	$ git diff
不带任何参数的`diff`命令会比较尚未暂存(unstaged)和已暂存的(staged)文件的区别。

    $ git diff --cached
    $ git diff --staged

这两个带参数的命令功能一致。用于比较已暂存的和已经commit的文件之间的变更。

#### 6.提交更新*(commit)*

commit命令用于将已经暂存的文件保存至Git Repository中。  
具体命令如下：

    $ git commit
不带任何参数提交方式会启动文本编辑器以输入提交的说明（message）。

    $ git commit -m [message]
带`-m`参数的命令可以将提交信息与命令放在同一行。

    $ git commit -a
带`-a`参数的命令可以跳过`add`步骤，直接commit所有已经跟踪过的所有文件。

#### 7.移除文件
+ 最普通的移除文件的方法是将文件从工作目录中删除，然后commit。但是这样的操作较为繁琐。
+ `git rm`可以一次性完成上述工作。
+ 如果文件已经添加至暂存区，那么需要使用`-f`参数强制删除，确保安全。因为删除之后文件不可恢复。
+ 如果只是想把文件从Git仓库(暂存区)中删除，但是不从磁盘中删除，那么可以使用带`--cached`参数的命令

具体命令如下：

    $ git rm [Filename]
    相当于
    $ rm [Filename]
    $ git add [Filename]
    $ git commit

#### 8.移动文件
移动文件的命令可以用于移动文也可以用于重命名。具体命令如下：

    $ git mv File_From File_To
	相当于
	$ mv File_From File_To
	$ git rm File_From
	$ git add File_To

#### 9.查看提交历史

###### **--不带参数**
    $ git log
不带参数的`git log`命令会列出所有的更新、每个commit的 SHA-1 校验和、作者的名字和电子邮件地址、提交时间以及提交说明。最近的更新排在最上面。

###### **-p选项**
	$ git log -p -time
带`-p`选项的命令用来显示每次内容提交的差异，`-time`表示仅显示最近`time`次的commit。
	
###### **--stat选项**
	$ git log --stat  //列出每个commit的简略统计信息。
#

###### **--Pretty 选项**
 这个选项可以指定使用不同于默认格式的方式展示提交历史。 这个选项有一些内建的子选项供你使用。 比如用 `oneline` 将每个提交放在一行显示，查看的提交数很大时非常有用。 另外还有 `short`，`full` 和 `fuller` 可以用，展示的信息或多或少有些不同，请自己动手实践一下看看效果如何。

`--format`可以定制要显示的记录格式。

例子：

	$ git log --pretty=format:"%h - %an, %ar : %s"
	ca82a6d - Scott Chacon, 6 years ago : changed the version number
	085bb3b - Scott Chacon, 6 years ago : removed unnecessary test
	a11bef0 - Scott Chacon, 6 years ago : first commit

Table 1. git log --pretty=format 常用的选项

| 选项 |说明|
| ---- |---|
|%H |提交对象（commit）的完整哈希字串|
|%h|提交对象的简短哈希字串|
|%T|树对象（tree）的完整哈希字串|
|%t|树对象的简短哈希字串|
|%P|父对象（parent）的完整哈希字串|
|%p|父对象的简短哈希字串|
|%an|作者（author）的名字|
|%ae|作者的电子邮件地址|
|%ad|作者修订日期（可以用 --date= 选项定制格式）|
|%ar|作者修订日期，按多久以前的方式显示|
|%cn|提交者（committer）的名字|
|%ce|提交者的电子邮件地址|
|%cd|提交日期|
|%cr|提交日期，按多久以前的方式显示|
|%s|提交说明|

###### --graph选项
	$ git log --graph
显示 ASCII 图形表示的分支合并历史。

###### --其他选项

	-(n)               //仅显示最近的 n 条提交
	--since, --after   //仅显示指定时间之后的提交。
	--until, --before  //仅显示指定时间之前的提交。
	--author           //仅显示指定作者相关的提交。
    --committer		   //仅显示指定提交者相关的提交。
	--grep             //仅显示含指定关键字的提交
	-S				   //仅显示添加或移除了某个关键字的提交

#### 10.撤销操作

###### --commit之后撤销
	$ git commit --amend
这个命令会将暂存区中的文件提交。 如果自上次提交以来你还未做任何修改（例如，在上次提交后马上执行了此命令），那么快照会保持不变，而你所修改的只是提交信息。

最终你只会有一个提交 - 第二次提交将代替第一次提交的结果。

###### --add之后撤销

	$ git reset <commit SHA1> <File>
这个命令表示将 `File` 文件的 `index` 和 `Git Repo` 的状态恢复到 `commit SHA1` 时的状态，但是不会改变 `Working Directory` 的状态（除非加个参数）。事实上 `reset` 命令也能撤销commit之后的更改，这里不想写出来。可以参考[Git官网对于 `reset` 命令的说明](https://git-scm.com/book/zh/v2/Git-%E5%B7%A5%E5%85%B7-%E9%87%8D%E7%BD%AE%E6%8F%AD%E5%AF%86#_git_reset)。

#### 11.远程仓库的使用

这里命令较多，所以我直接列出命令并用注释解释命令使用方式和用途。

    $ git remote         //列出远程仓库的简称（默认为origin)
	$ git remote -v      //列出远程仓库简称和对应读写url
	$ git remote add <shortname> <url> //增加一个名为shortname的远程仓库
	$ git fetch [remote-name]   //从远程仓库中获取数据（但不会自动合并）
	$ git push [remote-name] [branch-name] //向远程仓库推送数据
	$ git remote show [remote-name]        //查看远程仓库更多信息
	$ git remote rename <From> <To>        //重命名仓库
	$ git remote rm <name>                 //移除仓库

#### 12.Git标签
一般使用这个功能来标记重要节点（如V1.0）。

	$ git tag                 //查看当前标签
	$ git tag -l <find>       //查找标签
	$ git tag -a <Version> [-m] [message] //创建附注标签
	$ git tag <Version>       //创建轻量标签
	$ git tag -a <Version> <commit_SHA1>  //给历史commit打标签

#### 13. 分支
分支基本概念见Git官网：[分支简介](https://git-scm.com/book/zh/v2/Git-%E5%88%86%E6%94%AF-%E5%88%86%E6%94%AF%E7%AE%80%E4%BB%8B)  
在Git中鼓励使用分支。  
以下内容只介绍命令，不介绍概念。

	$ git branch -v                  //列出所有分支并产看最后一次提交
	$ git branch [--merged] [--no-merged] //筛选分支列出
	$ git branch <name>              //新建分支
	$ git checkout <name>            //切换分支
	$ git merge <name>               //合并name到当前分支
	$ git branch -d <name>           //删除分支
	
###### --冲突分支的合并
如果在两个分支中对同一个文件同时做了修改，合并时就会产生冲突。这时Git会提醒你，并且在产生冲突的文件中加上一些特殊的字段，便于你进行修改，它看起来会是这个样子：

	<<<<<<< HEAD:index.html
	<div id="footer">contact : email.support@github.com</div>
	=======
	<div id="footer">
 	please contact us at support@github.com
	</div>
	>>>>>>> iss53:index.html
这表示 HEAD 所指示的版本在这个区段的上半部分（`=======` 的上半部分），而 iss53 分支所指示的版本在 `=======` 的下半部分。  
为了解决冲突，你必须选择使用由 ======= 分割的两部分中的一个，或者你也可以自行合并这些内容。

最后当你解决完冲突之后，使用 `git commit` 命令提交。

###### --跟踪分支（上游分支）
克隆一个仓库时，Git会自动创建一个本地跟踪分支，跟踪 origin/master 的 master 分支。如果还想跟踪远程仓库的其他分支，可以自行添加。

	$ git checkout --track [remote]/[branch]//将本地分支名称与远程设为相同
	$ git checkout -b [remotename]/[branch] //自行设置本地分支名称

###### --删除远程分支
	$ git push <repo> --delete <branch>

#### 14.变基(Rebase)
之前讲的 `merge` 命令做的是一个简单的三方合并操作，具体如下图所示：
![merge实现](https://git-scm.com/book/en/v2/images/basic-rebase-1.png)
![merge实现](https://git-scm.com/book/en/v2/images/basic-rebase-2.png)

#

而`rebase`命令则是将一条分支上的内容复制过来以进行合并，如图所示：
![rebase实现](https://git-scm.com/book/en/v2/images/basic-rebase-3.png)
![rebase实现](https://git-scm.com/book/en/v2/images/basic-rebase-4.png)

###### --一个变基的例子

现在有如图所示的项目，如果你想要先把cient分支并入master然后再把server分支并入master该怎么操作呢？由于client不是直接从master分支出去的，所以这个情况看起来有点复杂，但是操作起来也还好。我们可以使用带 `--onto` 参数的 `rebase` 命令来完成。
![rebase example](https://git-scm.com/book/en/v2/images/interesting-rebase-1.png)

	$ git rebase --onto master server client

以上命令的意思是取出client分支，将其与server共同祖先之后的修改重放到master上。
操作之后结果如图所示：
![rebase example](https://git-scm.com/book/en/v2/images/interesting-rebase-2.png)
然后我们可以快进合并master分支。

	$ git checkout master
	$ git merge client

接下来把server分支也整合进来：

	$ git rebase master server
	$ git checkout master
    $ git merge server

###### --变基操作注意事项
**只对**尚未推送或分享给别人的本地修改执行变基操作清理历史，**从不对**已推送至别处的提交执行变基操作。  
否则别人本地仓库是未变基的版本，而你却将服务器上的仓库变更为了变基的版本。下次别人进行提交时就会产生混乱。
#### 其他

	$ git config --global alias.<alias> <command>  //创建命令别名

