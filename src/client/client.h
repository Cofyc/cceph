#ifndef CCEPH_CLIENT_H
#define CCEPH_CLIENT_H

#include "include/types.h"

struct cceph_client_ioctx_t {
	
};

struct cceph_client_pool_stat {
  uint64_t num_bytes;
  uint64_t num_objects;
};


struct cceph_client {
  char* name;

  int (* rados_create)(cceph_client_cluster_map **cluster_map);
  int (* raods_destory)(cceph_client_cluster_map **cluster_map);

  int (* rados_connect)(cceph_client_cluster_map *cluster_map);
  int (* raods_shutdown)(cceph_client_cluster_map *cluster_map);

  int (* pool_list)(cceph_client_cluster_map *cluster_map, 
  	char *buf, size_t len);
  int (* pool_create)(cceph_client_cluster_map *cluster_map, 
  	const char *pool_name);
  int (* pool_remove)(cceph_client_cluster_map *cluster_map, 
  	const char *pool_name);

  int (* ioctx_create)(cceph_client_cluster_map *cluster_map, 
  	const char *pool_name, cceph_client_ioctx_t **ioctx);
  int (* ioctx_destory)(cceph_client_ioctx_t **ioctx);

  int (* pool_stat)(cceph_client_ioctx_t *ioctx, 
  	struct cceph_client_pool_stat *stats);

  int (* read)(cceph_client_ioctx_t *ioctx, 
  	const char *oid, char *buf, size_t len, uint64_t off);
  int (* write)(cceph_client_ioctx_t *ioctx, 
  	const char*, const char*, size_t, uint_64);
  int (* write_full)(cceph_client_ioctx_t *ioctx, 
  	const char*, const char*, size_t);
  int (* append)(cceph_client_ioctx_t *ioctx, 
  	const char*, const char*, size_t);
  int (* remove)(cceph_client_ioctx_t *ioctx, 
  	const char *oid);
  int (* remove)(cceph_client_ioctx_t *ioctx, 
  	const char *oid);
  int (* truncate)(cceph_client_ioctx_t *ioctx, 
  	const char *oid, uint64_t size);
};

#endif
