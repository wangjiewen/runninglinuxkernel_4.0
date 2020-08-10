#include <linux/init.h>
#include <linux/list.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/mm.h>
#include <linux/rbtree.h>

struct mytype {
	struct rb_node node;
	int key;
};

struct rb_root mytree = RB_ROOT;

struct mytype *my_search(struct rb_root *root, int new) {
	struct rb_node *n = root->rb_node;

	while (n) {
		struct mytype *data = container_of(n, struct mytype, node);

		if (data->key > new)
			n = n->rb_left;
		else if (data->key < new)
			n = n->rb_right;
		else
			return data;
	}
	return NULL;
}

int my_insert(struct rb_root *root, struct mytype *data) {
	struct rb_node **new = &(root->rb_node), *parent = NULL;

	while (*new) {
		struct mytype *this = container_of(*new, struct mytype, node);

		parent = *new;
		if (this->key < data->key)
			new = &((*new)->rb_left);
		else if (this->key > data->key)
			new = &((*new)->rb_right);
		else
			return -1;
	}

	rb_link_node(&data->node, parent, new);
	rb_insert_color(&data->node, root);

	return 0;
}

static int __init my_init(void)
{
	int i;
	struct mytype *data;
	struct rb_node *n;

	for (i = 0; i < 20; i+= 2) {
		data = kmalloc(sizeof(struct mytype), GFP_KERNEL);
		data->key = i;
		my_insert(&mytree, data);
	}

	for (n = rb_first(&mytree); n; n = rb_next(n))
		printk("key=%d\n", rb_entry(n, struct mytype, node)->key);

	return 0;
}

static void __exit my_exit(void)
{
	struct mytype *data;
	struct rb_node *n;

	for (n = rb_first(&mytree); n;) {
		data = rb_entry(n, struct mytype, node);
		n = rb_next(n);
		if (data) {
			rb_erase(&data->node, &mytree);
			printk("erase key=%d\n", data->key);
			kfree(data);
		}
	}
}

module_init(my_init);
module_exit(my_exit);

MODULE_AUTHOR("JiewenWang");
MODULE_DESCRIPTION("rbtree test");
MODULE_LICENSE("GPL");
