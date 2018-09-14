#pragma once
#include <vector>
#include <memory>

class Bucket;

class INode 
{
public:
	int32_t flags_;
	int64_t pgid_;
	std::string key_;
	std::string value_;
};

class Node 
{
public:
	Node();
	virtual ~Node();
public:
	Node* Root();
	int MinKeys();
	int Size();
	bool SizeLessThan(int value);
	int PageElementSize();
	Node* ChildAt(int index);
	int ChildIndex(Node* child);
	int NumChildren();
	Node* NextSibling();
	Node* PrevSibling();
	void Put(const std::string& old_key,const std::string& new_key,const std::string& value,int64_t pgid,int32_t flags);
	void Del(const std::string& key);
	void Read();
	void Write();
	std::vector<Node*> Split(int page_size);
	std::vector<Node*> SplitTwo(int page_size);
	int SplitIndex(int threshold);
	int Spill();
	void Rebalance();
	void RemoveChild(Node* target);
	void Dereference();
	void Free();
private:
	std::weak_ptr<Bucket> bucket_;
	bool is_leaf_;
	bool is_unbalanced_;
	bool is_spilled_;
	std::string key_;
	int64_t pgid_;
	Node* parent_;
	std::vector<Node*> nodes_;
	std::vector<INode> inodes_;
};