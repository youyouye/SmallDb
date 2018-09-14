#pragma once
#include <vector>
class Bucket;
class Page;
class Node;

class ElemRef 
{
public:
	std::weak_ptr<Page> page_;
	std::weak_ptr<Node> node_;
	int index_;
};

class Cursor
{
public:
	Cursor();
	~Cursor();
private:
	std::weak_ptr<Bucket> bucket_;
	std::vector<ElemRef> stack_;
};

