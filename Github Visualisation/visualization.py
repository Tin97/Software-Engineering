from github import Github
import json

print("Enter your username: ")
username = input()

g = Github()

file = open('data.json','w')

print("You chose ", username)

print("There are following repositories: ")
for repo in g.get_user(username).get_repos():
    print(repo.name)


print("Choose one of the repositories or type 'exit'")

input = input()
#input = "Group30_app"

contributors = []
commits = []
data = []

found = False
for repo in g.get_user(username).get_repos():
    if ( input == repo.name ):
        found = True

        for contributor in repo.get_contributors():
            print(contributor.name)
            contributors.append(contributor.name)
            commits.append(0)

        for commit in repo.get_commits():
            author = commit.commit.author.name
            for i in range(len(contributors)):
                if author == contributors[i]:
                    commits[i]+=1

if ( found == False ):
    print("That repository doesn't exist!")

for i in range(len(commits)):
    print(contributors[i],commits[i])

for i in range(len(commits)):
    data.append(
        {
            'Letter': contributors[i],
            'Freq': commits[i]
        }
    )

json.dump(data, file)
