# 1、创建本地仓库
mkdir -p gocode
cd gocode

### 下载fork到本地
git clone https://github.com/aizhuzhudegua/linglong-hub.git

# 2、设置远程仓库

## ssh

git remote add upstream https://github.com/linuxdeepin/linglong-hub.git
git remote set-url origin git@github.com:aizhuzhudegua/linglong-hub.git

## 查看remote
git remote -v

# 3、创建分支

## 每次都要做rebase	

git fetch upstream
git checkout master
git rebase upstream/master

## 创建分支
git checkout -b 项目名

# 4、提交

## 在linglong-hub目录下
mkdir io.github.xxx

## 把yaml拷贝进去提交

git add io.github.xxx/linglong.yaml
git commit
git push origin 项目名

## 最后开一个pr,放项目截图

# 5、后期问题

## commit合并

git rebase -i HEAD~2
需要把第二个 pick 改成 s
编辑合并后的 commit message 的，直接删掉多余部分

# 6、其他操作

## 从最近一次commit恢复xxx
git checkout HEAD xxx

## 查看git状态
git status

## 查看分支
git branch -av

## 切换分支
git checkout -b xxx
-b：没有该分支会去创建 

## 管理干的事情：合并分支
git marge xxx

## 强制覆盖
git push --force origin xxx

# 7、rebase

1、git checkout xxx #切换分支
2、git rebase -i HEAD~要合并commit的数量

#在想要删除的分支前打上d

#冲突发生时（可选）
3、git add xxx/linglong.yaml    #确认提交xxx
  git rebase --continue


4、git push --force origin xxx #强制覆盖

git diff 5b1b0b068dd0afb13599bfe09e4b75681979d7d8
diff -u file1.txt file2.txt

# 8、版本回退

git clean -df

git reset --hard <commit-hash>

# 9、递归下载子模块

--recurse-submodules