#pragma once

class BranchPageElement 
{
public:
	unsigned int pos_;
	unsigned int ksize_;
	long int pgid_;
};

class LeafPageElement 
{
public:
	unsigned int flags_;
	unsigned int pos_;
	long int pgid_;
};

class Page 
{
public:

private:
	long int id_;
	unsigned int flags_;
	unsigned int count_;
	unsigned int overflow_;
	char* ptr_;
};