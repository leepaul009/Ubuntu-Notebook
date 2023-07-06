## Tips for Git
### Common
```
# show and set remote
git remote -v
git remote set-url origin https://leepaul009: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@github.com/leepaul009/apollo.git


# show and update user
git config --list
git config --global user.name "Alvin J. Alexander"
git config --global user.email [your email address here]

# show and update git editor
git config -e # show
git config --global core.editor "vim" # update

# check local branch
git branch
# check remote branch, and prefix with remotes is remote-branch
git branch -a
# create local branch 
git branch {NAME_OF_A_LOCAL_BRANCH}
# create and checkout to local branch 
git branch -b {NAME_OF_A_LOCAL_BRANCH}

# Delete all local branches except for “master”
git branch | grep -v "master" | xargs git branch -D

# Compare two branches
git diff branch1:path/to/file branch2:path/to/file

# download remote branch or updates of remote branch
git featch origin {remote_branch_name}

git checkout origin/{remote_branch_name} {dir want to update}
```

### Manage branch and master
```
# feature is downstream and master is upstream, I want to get updates of master in feature branch:
# when master(remote) has new commits that personal branch(local/remote) doesn't have:
A - B - C - E - D - F (master)
        \
         a - b (personal branch)
# we should do rebase to get new commits of master to personal branch(local)
A - B - C - E - D - F (master)
                    \
                     a - b (personal branch)
# then do:
git checkout master
git pull # get new commits
git checkout feature
git rebase master # try to get new commits of master

# but now we can not push changes to remote by 'git push' because remote graph is different from local
# if branch 'feature' is only for yourself:
git push --force origin feature
# else branch 'feature' is only for multiple person:
git push --force-with-lease origin feature  # 使用该命令在强制覆盖前会进行一次检查如果其他人在该分支上有提交会有一个警告，此时可以避免福改代码的风险。

```

### Edit commits
```
# save temporary changes:
git stash list
git stash pop # pop lastest one
git stash drop            # drop top hash, stash@{0}
git stash drop stash@{n}  # drop specific stash - see git stash list

# make all changes after {commit_hash} to uncommitted local changes
# it merge all commits after {commit_hash} to one commit
git reset --soft {commit_hash}

# 
git cherry-pick {commit_hash}
```
