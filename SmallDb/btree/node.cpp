#include "node.h"
#include "../base/constant.h"

Node::Node()
{
}

Node::~Node()
{

}

Node* Node::Root()
{
	if (parent_ == nullptr)
		return nullptr;
	return parent_->Root();
}

int Node::MinKeys()
{
	if (is_leaf_)
		return 1;
	return 2;
}

int Node::Size()
{
	auto size = pageHeaderSize;
	auto element_size = PageElementSize();
	for (int i = 0;i<inodes_.size();i++)
	{
		auto item = inodes_[i];
		size += element_size + item.key_.size() + item.value_.size();
	}
	return size;
}

bool Node::SizeLessThan(int value)
{
	auto size = pageHeaderSize;
	auto element_size = PageElementSize();
	for (int i = 0;i<inodes_.size();i++)
	{
		auto item = inodes_[i];
		size += element_size + item.key_.size() + item.value_.size();
		if (size > value)
		{
			return false;
		}
	}
	return true;
}

int Node::PageElementSize()
{
	if (is_leaf_)
	{
		return leafPageElementSize;
	}
	return branchPageElementSize;
}

Node* Node::ChildAt(int index)
{
	if (is_leaf_)
		return nullptr;
	if (!bucket_.expired())
	{
		auto temp = bucket_.lock();
	}
	return nullptr;
}

int Node::ChildIndex(Node* child)
{
}

int Node::NumChildren()
{
	return inodes_.size();
}

Node* Node::NextSibling()
{
}

Node* Node::PrevSibling()
{
}

void Node::Put(const std::string& old_key, const std::string& new_key, const std::string& value, int64_t pgid, int32_t flags)
{

}

void Node::Del(const std::string& key)
{
}

void Node::Read()
{
}

void Node::Write()
{
}

std::vector<Node*> Node::Split(int page_size)
{
}

std::vector<Node*> Node::SplitTwo(int page_size)
{
}

int Node::SplitIndex(int threshold)
{
}

int Node::Spill()
{
}

void Node::Rebalance()
{
}

void Node::RemoveChild(Node* target)
{
}

void Node::Dereference()
{
}

void Node::Free()
{
}
