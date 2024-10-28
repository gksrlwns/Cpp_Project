#pragma once
struct FlipbookInfo;
class ResourceBase;
class Texture;
class Sprite;
class Flipbook;
class ResourceManager
{
	DECLARE_SINGLE(ResourceManager);

public:
	void Init();
	void Release();

public:
	Texture* LoadTexture(const wstring& key, const wstring& path, uint32 transparent = RGB(255, 0, 255));
	Texture* GetTexture(const wstring& key);

	Sprite* CreateSprite(const wstring& key, Texture* texture, int x = 0, int y = 0, int cx = 0, int cy = 0);
	Sprite* GetSprite(const wstring& key);

	Flipbook* CreateFlipbook(const wstring& key, FlipbookInfo info);
	Flipbook* GetFlipbook(const wstring& key);

private:
	wstring _resourcePath;

	// map => binary tree 
	// map => 검색이 빠르다.
	map<wstring, ResourceBase*> _resources = {};
};

#define Resource GET_SINGLE(ResourceManager)