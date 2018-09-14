#include "bucket.h"
#include "../btree/node.h"
#include "../page/page.h"

std::shared_ptr<Bucket> Bucket::NewBucket()
{
}

std::shared_ptr<Tx> Bucket::GetTx()
{
}

long int Bucket::Root()
{
}

bool Bucket::Writable()
{
}

std::shared_ptr<Cursor> Bucket::GetCursor()
{
}

std::shared_ptr<Bucket> Bucket::GetBucket(const std::string& name)
{
}

std::shared_ptr<Bucket> Bucket::OpenBucket(const std::string& value)
{
}

std::shared_ptr<Bucket> Bucket::CreateBucket(const std::string& key)
{
}

std::shared_ptr<Bucket> Bucket::CreateBucketIfNotExists(const std::string& key)
{
}

void Bucket::DeleteBucket(const std::string& key)
{
}

std::string Bucket::Get()
{
}

bool Bucket::Put(const std::string& key, const std::string& value)
{
}

void Bucket::Delete(const std::string& key)
{
}

long int Bucket::Sequence()
{
}

bool Bucket::SetSequence(long int value)
{
}

long int Bucket::NextSequence()
{
}