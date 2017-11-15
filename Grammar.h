/*===============================================================
*   Copyright (C) 2016 All rights reserved.
*   
*   文件名称：Grammer.h
*   创 建 者：unicodeproject
*   创建日期：2016年07月20日
*   描    述：do not take empty prodution into consideration
*   备    注: 
*   更新日志：
*
================================================================*/

#ifndef _GRAMMER_H
#define _GRAMMER_H
#include<iostream>
#include<string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include "common.h"
// please add your code here!
class Grammar
{
public:
    std::string StartSymbol;
    Grammar(std::string startsymbol) {
        StartSymbol=startsymbol;
    }
    ~Grammar() {
    m_terminals.clear();
    m_nonterminals.clear();
    m_rules.clear();
    m_id2rules.clear();
    m_symbols.clear();
    m_firstset.clear();
    m_followset.clear();
    }
    std::unordered_map<std::string,std::vector<std::string> > m_morphmap;
    std::unordered_map<std::string,int> m_terminals;
    std::unordered_map<std::string,int> m_nonterminals;
    std::unordered_map<std::string,int> m_rules;
    std::unordered_map<int,std::string> m_id2rules;
    std::unordered_set<std::string> m_symbols;
    std::unordered_map<std::string,std::string> m_firstset;
    std::unordered_map<std::string,std::string> m_followset;
    //load the grammar rules 
    int LoadGrammarRules(const char* path);
    int LoadVocab(const char* path);
    // load Nonterminals of the grammar
    int LoadNonterminals(const char* path);
    // load Terminals of the Grammar
    int LoadTerminals(const char* path);
    // get the terminals and nonterminals;
    int GetSymbols();
    // the Nonterminals' first set;
    std::unordered_map<std::string,std::string> m_firsts;
    // the Nonterminals's follow set;
    std::unordered_map<std::string,std::string> m_follows;
    // given a Nonterminal calc the firstset;
    int GetSingleFirst(std::string elem, std::string &firststr);
    // given a Nonterminal calc the followset;
    int GetSingleFollow(std::string elem, std::string &firststr);
    // get all Nonterminals's first set;
    int GetFirstSet();
    // get all Nonterminal's follow set;
    int GetFollowSet();
    //given a head ,return the string that appears first in production
    int GetFirstElemInRuleBody(std::string head,std::unordered_set<std::string> &elems);
    // assist follow set calc
    int GetHeadAndNeighborSet(std::string bodyelem,std::unordered_set<std::string> &headelems, std::unordered_set<std::string> &neighborelems);
    // used after GetFirstElemInRuleBody, to see if all the elem appears first is Nonterminals or not
    bool isAllTerminals(std::unordered_set<std::string> &itsset, std::vector<std::string>& nontermvec); 
    
};
#endif
