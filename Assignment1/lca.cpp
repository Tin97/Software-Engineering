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
        //when tree object created sets root to NULL
        btree()
        {
          root = NULL;
        }

        //public lowest common ancestor function, calls the pricate function
        int lca(int n1, int n2)
        {
          return findLCA(root, n1, n2);
        }

        //insert the node with the value key
        void insert(int key)
        {
            //if the tree is not empty calls the recursive insert function
            if(root!=NULL)
              insert(key, root);
            //if the tree is empty set the key value to be the given key
            else
            {
              root=new node;
              root->key=key;
              root->left=NULL;
              root->right=NULL;
            }
        }

        void destroy()
        {
          if ( root != NULL )
          {
            destroy(root);
          }
        }

    private:
      //returns the key value of the lowest common ancestor
      int findLCA(node *root, int n1, int n2)
      {
          vector<int> path1, path2;

          //first checks whether the keys exist and if they do stores
          //key values (path) in vector objects
          if ( !findPath(root, path1, n1) || !findPath(root, path2, n2))
                return -1;

          int i;

          //compares values from two different paths, when they are not
          //the same for loop breakes and returns the last same key
          //from the path
          for (i = 0; i < path1.size() && i < path2.size() ; i++)
              if (path1[i] != path2[i])
                  break;
          return path1[i-1];
      }

      //find the path for a specific node from the root node
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

      //insert the node with the key value recursively
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

        void destroy (node *leaf)
        {
          if ( leaf != NULL )
          {
            destroy(leaf->left);
            destroy(leaf->right);
            free(leaf);
          }

          return;
        }

        node *root;
};

//catch2 unit testing
TEST_CASE( "Lowest common ancestor", "[lca]" ) {
    btree tree = btree();
    tree.insert(7);
    tree.insert(3);
    tree.insert(1);
    tree.insert(10);
    tree.insert(8);
    tree.insert(13);
    tree.insert(4);
    REQUIRE( tree.lca(7, 3) == 7);
    REQUIRE( tree.lca(1, 4) == 3);
    REQUIRE( tree.lca(4, 13) == 7);
    REQUIRE( tree.lca(13, 10) == 10);
    REQUIRE( tree.lca(10, 3) == 7);
    REQUIRE( tree.lca(5, 3) == -1);

    btree tree1 = btree();
    REQUIRE( tree.lca(3, 11) == -1 );

    tree1.insert(1);
    tree1.insert(2);
    REQUIRE( tree1.lca(2, 2) == 2 );

    btree tree2 = btree();
    tree2.insert(5);
    tree2.insert(4);
    tree2.insert(3);
    tree2.insert(2);
    tree2.insert(1);
    REQUIRE( tree2.lca(1, 5) == 5);

    tree.destroy();
    tree1.destroy();
    tree2.destroy();
}
