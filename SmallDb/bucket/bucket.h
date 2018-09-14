#pragma once
#include <memory>
#include <map>
#include <string>
#include <functional>

class Node;
class Page;
class Tx;
class Cursor;

class bucket 
{
public:
	long int root_;
	long int sequence_;
};

class Bucket 
{
public:
	std::shared_ptr<Bucket> NewBucket();
	std::shared_ptr<Tx> GetTx();
	long int Root();
	bool Writable();
	std::shared_ptr<Cursor> GetCursor();
	std::shared_ptr<Bucket> GetBucket(const std::string& name);
	std::shared_ptr<Bucket> OpenBucket(const std::string& value);
	std::shared_ptr<Bucket> CreateBucket(const std::string& key);
	std::shared_ptr<Bucket> CreateBucketIfNotExists(const std::string& key);
	void DeleteBucket(const std::string& key);
	std::string Get();
	bool Put(const std::string& key,const std::string& value);
	void Delete(const std::string& key);
	long int Sequence();
	bool SetSequence(long int value);
	long int NextSequence();
	void ForEach(std::function<void(std::string,std::string)> func);
	
private:
	std::shared_ptr<bucket> bucket_;
	std::weak_ptr<Tx> tx_;
	std::map<std::string, std::shared_ptr<Bucket>> buckets_;
	std::weak_ptr<Page> page_;
	std::weak_ptr<Node> root_node_;
	std::map<int64_t, std::shared_ptr<Bucket>> nodes_;
	float fill_percent_;
};