/*===============================================================
*   Copyright (C) 2017 All rights reserved.
*   
*   FileName:ParseTree.cpp
*   creator:yuliu1@microsoft.com
*   Time:11/13/2017
*   Description:
*   Notice: 
*   Updates:
*
================================================================*/
 
#include "ParseTree.h"
#include "common.h"
#include <stdlib.h>

// please add your code here!
void ParseTree::ConstructParseTree(ContentNode* content, int index)
{
  std::vector<std::string> strids;
  SplitString(content[index].paths,strids,",");
  root->childrenNum = strids.size();
  root->children = new TreeNode* [root->childrenNum];
  for (int i = 0; i < root->childrenNum;i++)
  {
    root->children[i] = ConstructParseTreeRecursively(content,atoi(strids[i].c_str()));
  }
   
}
TreeNode* ParseTree::ConstructParseTreeRecursively(ContentNode* content, int index)
{
  TreeNode *node = new TreeNode(content[index].grammarsymbol);
  if (strcmp(content[index].paths,"")==0)
  {
    node->childrenNum = 1;
    TreeNode *leafnode = new TreeNode(content[index].realsymbol);
    leafnode->childrenNum = 0;
    node->children = new TreeNode* [1];
    node->children[0] = leafnode;
  }
  else
  {
    std::vector<std::string> strids;
    SplitString(content[index].paths,strids,",");
    node->childrenNum = strids.size();
    node->children = new TreeNode* [node->childrenNum];
    for (int i = 0; i < node->childrenNum;i++)
    {
      node->children[i] = ConstructParseTreeRecursively(content,atoi(strids[i].c_str()));
    }
  }
  return node;
}


std::string ParseTree::RetrieveParseTree()
{
  std::string result;
  result += root->symbol;
  result += "[";
  for (int i = 0; i < root->childrenNum;i++)
  {
    result += RetrieveParseTreeRecursively(root->children[i]); 
  }
  result += "]";
  return result;
}

std::string ParseTree::RetrieveParseTreeRecursively(TreeNode *node)
{
  std::string result;
  if(node->childrenNum==0)
  {
    result += node->symbol;
  }
  else
  {
    result += node->symbol;
    result += "[";
    for (int i = 0; i < node->childrenNum;i++)
    {
      result += RetrieveParseTreeRecursively(node->children[i]);
    }
    result += "]";
  }
  return result;
}

std::vector<std::pair<std::string,std::string> > ParseTree::RetrieveSyllablesFromTree(std::string startSymbol)
{
  std::string result = "";
  std::vector<std::string> myresults;
  std::vector<std::string> grammarresults;
  std::vector<std::pair<std::string, std::string> > allresults;
  for (int i = 0; i < root->childrenNum;i++)
  {
    RetrieveSyllablesFromTreeRecursively(root->children[i],myresults,grammarresults,startSymbol);
  }
  for (int i = 0; i < myresults.size();i++)
  {
    allresults.push_back(std::make_pair(myresults[i],grammarresults[i]));
  }
  
  return allresults;
}

std::string ParseTree::RetrieveSyllablesFromTreeRecursively(TreeNode *node,std::vector<std::string>&syllables,std::vector<std::string>&grammarresults, std::string startSymbol)
{
  std::string result = "";
  if (node->childrenNum==0)
  {
    result=node->symbol;
  }
  else
  {
    for (int i = 0;i<node->childrenNum;i++)
    {
      if (i > 0)
      {
        result += ",";
      }
        result += RetrieveSyllablesFromTreeRecursively(node->children[i],syllables,grammarresults,startSymbol);
    }
    if (node->symbol==startSymbol)
    {
      syllables.push_back(result);
      std::string newstr;
      for (int i = 0; i < node->childrenNum;i++)
      {
          if (i!=0)
          {
            newstr+=",";
          }
          newstr+= node->children[i]->symbol;
      }
      grammarresults.push_back(newstr);
    }
  }
  return result;
}
ParseTree::~ParseTree()
{
  for (int i = 0; i<root->childrenNum;i++)
  {
    DeleteParseTreeRecursively(root->children[i]);
  }
  if (root->children!=NULL)
  {
    delete [ ] root->children;
    root->children = NULL;
  }
  if (root!=NULL)
  {
    delete root;
    root = NULL;
  }
}
void ParseTree::DeleteParseTreeRecursively(TreeNode *node)
{
  if (node->childrenNum==0)
  {
    delete node;
    node = NULL;
  }
  else
  {
      for (int i = 0; i<node->childrenNum;i++)
      {
        DeleteParseTreeRecursively(node->children[i]);
      }
      if (node->children != NULL)
      {
        delete [ ] node->children;
      }
      if (node!=NULL)
      {
        delete node;
        node = NULL;
      }
  }
}
