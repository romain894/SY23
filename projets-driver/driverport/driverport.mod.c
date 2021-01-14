#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0xe271ed87, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x33ba5cd4, __VMLINUX_SYMBOL_STR(param_ops_bool) },
	{ 0xc432cb6d, __VMLINUX_SYMBOL_STR(misc_deregister) },
	{ 0xe61a6d2f, __VMLINUX_SYMBOL_STR(gpio_unexport) },
	{ 0xa8f59416, __VMLINUX_SYMBOL_STR(gpio_direction_output) },
	{ 0x65d6d0f0, __VMLINUX_SYMBOL_STR(gpio_direction_input) },
	{ 0x73f48ce0, __VMLINUX_SYMBOL_STR(gpio_export) },
	{ 0xa76dc964, __VMLINUX_SYMBOL_STR(misc_register) },
	{ 0xc671e369, __VMLINUX_SYMBOL_STR(_copy_to_user) },
	{ 0x960661f4, __VMLINUX_SYMBOL_STR(gpio_get_value) },
	{ 0xc40f91c2, __VMLINUX_SYMBOL_STR(gpio_set_value) },
	{ 0x20c55ae0, __VMLINUX_SYMBOL_STR(sscanf) },
	{ 0xb5419b40, __VMLINUX_SYMBOL_STR(_copy_from_user) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=driver_class_gpio";

