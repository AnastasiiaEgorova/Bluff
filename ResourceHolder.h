#pragma once
#include <string>
#include <memory>
#include <cassert>
#include <map>
#include <stdexcept>

template <typename R, typename ID>
class ResourceHolder
{
public:
	void				load(ID id, const std::string& filename);

	template <typename P>
	void				load(ID id, const std::string& filename, const P& secondParam);

	const R&			get(ID id) const;
	R&					get(ID id);

private:
	void				insertResource(ID id, std::unique_ptr<R> resource);

private:
	std::map<ID, std::unique_ptr<R>> resourceMap;
};

template <typename R, typename ID>
void ResourceHolder<R, ID>::load(ID id, const std::string& filename) {

	std::unique_ptr<R> resource(new R());
	if (!resource->loadFromFile(filename))
		throw std::runtime_error("ResourceHolder::load - Failed to load " + filename);

	// If loading successful, insert resource to map
	insertResource(id, std::move(resource));
}

template <typename R, typename ID>
template <typename Paramater>
void ResourceHolder<R, ID>::load(ID id, const std::string& filename, const Paramater& secondParam) {

	// Create and load resource
	std::unique_ptr<R> resource(new R());
	if (!resource->loadFromFile(filename, secondParam))
		throw std::runtime_error("ResourceHolder::load - Failed to load " + filename);

	// If loading successful, insert resource to map
	insertResource(id, std::move(resource));
}

template <typename R, typename ID>
R& ResourceHolder<R, ID>::get(ID id) {

	auto found = resourceMap.find(id);
	assert(found != resourceMap.end());

	return *found->second;
}

template <typename R, typename ID>
const R& ResourceHolder<R, ID>::get(ID id) const {

	auto found = resourceMap.find(id);
	assert(found != resourceMap.end());

	return *found->second;
}

template <typename R, typename ID>
void ResourceHolder<R, ID>::insertResource(ID id, std::unique_ptr<R> resource)
{
	// Insert and check success
	auto inserted = resourceMap.insert(std::make_pair(id, std::move(resource)));
	assert(inserted.second);
}