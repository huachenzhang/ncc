typdef struct Map Map;

Map *make_map();
Map *make_map_parent(Map *parent);
void *map_get(Map *map, char *key);
void *map_put(Map *map, char *key, void *value);
void map_remove(Map *map, char *key);
int map_size(Map *map);
