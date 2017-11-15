/*===============================================================
*   Copyright (C) 2017 All rights reserved.
*   
*   FileName:ParseTree.h
*   creator:yuliu1@microsoft.com
*   Time:11/13/2017
*   Description:
*   Notice: 
*   Updates:
*
================================================================*/
 
#ifndef _PARSETREE_H
#define _PARSETREE_H
// please add your code here!
#include<string>
#include<utility>
#include "GraphStack.h"
struct TreeNode
{
  std::string symbol;
  TreeNode** children;
  int childrenNum;
  TreeNode(std::string symbol)
  {
    this->symbol = symbol;
    children = NULL;
    childrenNum = 0;
  }
};
class ParseTree
{
  public: 
      ParseTree(std::string startSymbol)
      {
        root = new TreeNode(startSymbol);
      }
      void ConstructParseTree(ContentNode *content, int index);
      TreeNode* ConstructParseTreeRecursively(ContentNode* content, int index);
      std::string RetrieveParseTree();
      std::string RetrieveParseTreeRecursively(TreeNode *node);
      std::vector<std::pair<std::string, std::string> > RetrieveSyllablesFromTree(std::string startSymbol);
      std::string RetrieveSyllablesFromTreeRecursively(TreeNode *node,std::vector<std::string>&syllables,std::vector<std::string>&grammarsymbols,std::string startSymbol);
      void DeleteParseTreeRecursively(TreeNode *node);
      ~ParseTree();
  private:
      TreeNode *root;

};
#endif
