from github import Github

print("Enter your username: ")
username = input()

g = Github()

print("You chose ", username)

print("There are following repositories: ")
for repo in g.get_user().get_repos(username):
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
            
            for contributor in repo.get_contributors():
                print(contributor.name)

    if ( found == False ):
        print("That repository doesn't exist, try again!")
