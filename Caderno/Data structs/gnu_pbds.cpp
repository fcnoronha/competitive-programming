
// GNU_pbds ordered set
// RB-tree that allow indexed access in O(logn)
// Change T to the type

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds ;
typedef tree< T, null_type,less< T >,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

ordered_set q;
q.insert(1);
auto it = q.find_by_order(k) // k-esimo elemento
auto it = q.oder_by_key(k) // quantos elementos são menores que k
