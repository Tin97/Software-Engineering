#include <cstdio>
#include <iostream>
#include <vector>
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"


using namespace std;

struct node
{
  int key;
  node *left;
  node *right;
};

class btree
{
    public:
        btree()
        {
          root = NULL;
        }

        int lca(int n1, int n2)
        {
          return findLCA(root, n1, n2);
        }

        void insert(int key)
        {
            if(root!=NULL)
              insert(key, root);
            else
            {
              root=new node;
              root->key=key;
              root->left=NULL;
              root->right=NULL;
            }
        }

    private:
      int findLCA(node *root, int n1, int n2)
      {
          vector<int> path1, path2;

          if ( !findPath(root, path1, n1) || !findPath(root, path2, n2))
                return -1;

          int i;
          for (i = 0; i < path1.size() && i < path2.size() ; i++)
              if (path1[i] != path2[i])
                  break;
          return path1[i-1];
      }

      bool findPath(node *root, vector<int> &path, int k)
      {
          if (root == NULL) return false;

          path.push_back(root->key);

          if (root->key == k)
              return true;

          if ( (root->left && findPath(root->left, path, k)) ||
               (root->right && findPath(root->right, path, k)) )
              return true;

          path.pop_back();
          return false;
      }

      void insert(int key, node *leaf)
      {
          if(key< leaf->key)
          {
            if(leaf->left!=NULL)
             insert(key, leaf->left);
            else
            {
              leaf->left=new node;
              leaf->left->key=key;
              leaf->left->left=NULL;
              leaf->left->right=NULL;
            }
          }
          else if(key>=leaf->key)
          {
            if(leaf->right!=NULL)
              insert(key, leaf->right);
            else
            {
              leaf->right=new node;
              leaf->right->key=key;
              leaf->right->left=NULL;
              leaf->right->right=NULL;
            }
          }
        }

        node *root;
};

TEST_CASE( "Lowest common ancestor", "[lca]" ) {
    btree tree = btree();
    tree.insert(7);
    tree.insert(3);
    tree.insert(1);
    tree.insert(10);
    tree.insert(8);
    tree.insert(13);
    tree.insert(4);
    REQUIRE( tree.lca(1, 4) == 3);
    REQUIRE( tree.lca(4, 13) == 7);
    REQUIRE( tree.lca(13, 10) == 10);
    REQUIRE( tree.lca(10, 3) == 7);
    REQUIRE( tree.lca(5, 3) == -1);

}
