from github import Github

g = Github("Tin97", "23081997pc")

for repo in g.get_user().get_repos():
    print(repo.name)
