#include "pch.h"
#include "ResourceManager.h"
#include "ResourceBase.h"
#include "Texture.h"
#include "Sprite.h"

void ResourceManager::Init()
{
	_resoureces.clear();
	_resourcePath = L"../Resources/";
}

void ResourceManager::Release()
{
	for (auto& item : _resoureces)
	{
		SAFE_DELETE(item.second);
	}
	_resoureces.clear();
}
Texture* ResourceManager::LoadTexture(const wstring& key, const wstring& path, uint32 transparent)
{
	if (_resoureces.contains(key))
	{
		return GetTexture(key);
	}
	wstring fullPath = _resourcePath + path;
	Texture* texture = new Texture();
	texture->LoadBmp(fullPath);
	texture->SetTransparent(transparent);

	_resoureces[key] = texture;
	return texture;
}
Texture* ResourceManager::GetTexture(const wstring& key)
{
	return dynamic_cast<Texture*>(_resoureces[key]);
}
Sprite* ResourceManager::CreateSprite(const wstring& key, Texture* texture, int x, int y, int cx, int cy )
{
	if (_resoureces.contains(key))
	{
		return GetSprite(key);
	}
	if (cx == 0)
	{
		cx = texture->GetSize().x;
	}
	if (cy == 0)
	{
		cy = texture->GetSize().y;
	}
	
	Sprite* sprite = new Sprite(texture,x,y,cx,cy);
	_resoureces[key] = sprite;

	return sprite;
}
Sprite* ResourceManager::GetSprite(const wstring& key)
{
	return dynamic_cast<Sprite*>(_resoureces[key]);
}