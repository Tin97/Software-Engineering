from github import Github

print("Enter your username: ")
username = input()

print("Enter your password: ")
password = input()

g = Github(username, password)

print("Logged into " + g.get_user().name)

print("There are following repositories: ")
for repo in g.get_user().get_repos():
    print(repo.name)

while True:
    print("Choose one of the repositories or type 'exit'")
    input = input()
    if ( input == "exit"):
        print("Goodbye")
        break

    found = False
    for repo in g.get_user().get_repos():
        if ( input == repo.name ):
            found = True
            print()
            print("Showing all commit dates and authors:")
            for commit in repo.get_commits():
                print(commit.commit.author.name)
                print(commit.commit.author.date)
            print()
            print("Showing all contributors:")
            for contributor in repo.get_contributors():
                print(contributor.name)

    if ( found == False ):
        print("That repository doesn't exist, try again!")
