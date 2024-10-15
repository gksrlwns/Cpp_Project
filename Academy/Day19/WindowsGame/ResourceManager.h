#pragma once
class ResourceManager
{
	DECLARE_SINGLE(ResourceManager);

public:
	void Init();
	void Release();
};

#define Resource GET_SINGLE(ResourceManager)