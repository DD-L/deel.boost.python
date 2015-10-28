# deel.boost.python

基于 Boost Version 1.59.0 / boost.python 修订

-----------------------------


#### Description：

如果采用将boost.python源码嵌入工程编译的方式，可能会出现诸如以下警告（gcc4.8.3 / CYGWIN-NT-6.1 / i686-Cygwin / boost-1-59-0）：

boost-1.59.0 版本的python库和boost-1.57.0的python库相比有所改善, 但仍能看到很多这样的gcc的警告。

<pre>	
$ g++ -Wall ...

boost_1_59_0/boost/python/cast.hpp: 在函数‘void boost::python::detail::assert_castable(boost::type<Target>*)’中:
boost_1_59_0/boost/python/cast.hpp:73:20: 警告：typedef ‘must_be_a_complete_type’ locally defined but not used [-Wunused-local-typedefs]
       typedef char must_be_a_complete_type[sizeof(T)];
                    ^
In file included from boost_1_59_0/boost/python/object/make_instance.hpp:9:0,
                 from boost_1_59_0/boost/python/object/make_ptr_instance.hpp:8,
                 from boost_1_59_0/boost/python/to_python_indirect.hpp:11,
                 from boost_1_59_0/boost/python/converter/arg_to_python.hpp:10,
                 from boost_1_59_0/boost/python/call.hpp:15,
                 from boost_1_59_0/boost/python/object_core.hpp:14,
                 from boost_1_59_0/boost/python/args.hpp:25,
                 from boost_1_59_0/boost/python.hpp:11,
boost_1_59_0/boost/python/object/instance.hpp: 在全局域：
boost_1_59_0/boost/python/object/instance.hpp:14:36: 警告：类型属性在定义后被忽略 [-Wattributes]
   struct BOOST_PYTHON_DECL_FORWARD instance_holder;
                                    ^
In file included from boost_1_59_0/boost/python/data_members.hpp:15:0,
                 from boost_1_59_0/boost/python/class.hpp:17,
                 from boost_1_59_0/boost/python.hpp:18,
boost_1_59_0/boost/python/make_function.hpp: 在函数‘boost::python::api::object boost::python::detail::make_function_aux(F, const CallPolicies&, const Sig&, const keyword_range&, NumKeywords)’中:
boost_1_59_0/boost/python/make_function.hpp:58:32: 警告：typedef ‘assertion’ locally defined but not used [-Wunused-local-typedefs]
           >::too_many_keywords assertion;
                                ^
In file included from boost_1_59_0/boost/python/class.hpp:20:0,
                 from boost_1_59_0/boost/python.hpp:18,
boost_1_59_0/boost/python/init.hpp: 在构造函数‘boost::python::init<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14>::init(const char*, const boost::python::detail::keywords<N>&)’中:
boost_1_59_0/boost/python/init.hpp:227:34: 警告：typedef ‘assertion’ locally defined but not used [-Wunused-local-typedefs]
             >::too_many_keywords assertion;
                                  ^
boost_1_59_0/boost/python/init.hpp: 在构造函数‘boost::python::init<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14>::init(const boost::python::detail::keywords<N>&, const char*)’中:
boost_1_59_0/boost/python/init.hpp:236:34: 警告：typedef ‘assertion’ locally defined but not used [-Wunused-local-typedefs]
             >::too_many_keywords assertion;
                                  ^
In file included from boost_1_59_0/boost/python/class.hpp:24:0,
                 from boost_1_59_0/boost/python.hpp:18,
boost_1_59_0/boost/python/object/pickle_support.hpp: 在静态成员函数‘static void boost::python::detail::pickle_suite_registration::register_(Class_&, ...)’中:
boost_1_59_0/boost/python/object/pickle_support.hpp:110:31: 警告：typedef ‘error_type’ locally defined but not used [-Wunused-local-typedefs]
           Class_>::error_type error_type;
                               ^
In file included from boost_1_59_0/boost/python.hpp:18:0,
boost_1_59_0/boost/python/class.hpp: 在静态成员函数‘static void boost::python::detail::error::virtual_function_default<T, Fn>::must_be_derived_class_member(const Default&)’中:
boost_1_59_0/boost/python/class.hpp:143:68: 警告：typedef ‘test1’ locally defined but not used [-Wunused-local-typedefs]
             typedef typename assertion<is_polymorphic<T> >::failed test1;
                                                  ^
boost_1_59_0/boost/python/class.hpp:145:81: 警告：typedef ‘test2’ locally defined but not used [-Wunused-local-typedefs]
             typedef typename assertion<is_member_function_pointer<Fn> >::failed test2;
                                                  ^
In file included from boost_1_59_0/boost/python.hpp:22:0,
boost_1_59_0/boost/python/def.hpp: 在函数‘void boost::python::detail::def_from_helper(const char*, const F&, const Helper&)’中:
boost_1_59_0/boost/python/def.hpp:40:19: 警告：typedef ‘assertion’ locally defined but not used [-Wunused-local-typedefs]
           >::type assertion;
                   ^
In file included from boost_1_59_0/boost/python.hpp:41:0,
boost_1_59_0/boost/python/make_constructor.hpp: 在函数‘boost::python::api::object boost::python::detail::make_constructor_aux(F, const CallPolicies&, const Sig&, const keyword_range&, NumKeywords)’中:
boost_1_59_0/boost/python/make_constructor.hpp:177:32: 警告：typedef ‘assertion’ locally defined but not used [-Wunused-local-typedefs]
           >::too_many_keywords assertion;
                                ^
In file included from boost_1_59_0/boost/python/object/make_instance.hpp:9:0,
                 from boost_1_59_0/boost/python/object/make_ptr_instance.hpp:8,
                 from boost_1_59_0/boost/python/to_python_indirect.hpp:11,
                 from boost_1_59_0/boost/python/converter/arg_to_python.hpp:10,
                 from boost_1_59_0/boost/python/call.hpp:15,
                 from boost_1_59_0/boost/python/object_core.hpp:14,
                 from boost_1_59_0/boost/python/object.hpp:9,
                 from boost_1_59_0/boost/python/tuple.hpp:10,
                 from boost_1_59_0/boost/python/numeric.hpp:10,
                 from boost_1_59_0/libs/python/src/numeric.cpp:6,
boost_1_59_0/boost/python/object/instance.hpp:14:36: 警告：类型属性在定义后被忽略 [-Wattributes]
   struct BOOST_PYTHON_DECL_FORWARD instance_holder;
                                    ^
In file included from boost_1_59_0/boost/python/refcount.hpp:9:0,
                 from boost_1_59_0/boost/python/to_python_indirect.hpp:19,
                 from boost_1_59_0/boost/python/converter/arg_to_python.hpp:10,
                 from boost_1_59_0/boost/python/call.hpp:15,
                 from boost_1_59_0/boost/python/object_core.hpp:14,
                 from boost_1_59_0/boost/python/object.hpp:9,
                 from boost_1_59_0/boost/python/tuple.hpp:10,
                 from boost_1_59_0/boost/python/numeric.hpp:10,
                 from boost_1_59_0/libs/python/src/numeric.cpp:6,
boost_1_59_0/boost/python/cast.hpp: 在函数‘void boost::python::detail::assert_castable(boost::type<T>*)’中:
boost_1_59_0/boost/python/cast.hpp:73:20: 警告：typedef ‘must_be_a_complete_type’ locally defined but not used [-Wunused-local-typedefs]
       typedef char must_be_a_complete_type[sizeof(T)];
                    ^
In file included from boost_1_59_0/libs/python/src/object/class.cpp:15:0,
                 from pyprebuild.cpp:17:
boost_1_59_0/boost/python/object/pickle_support.hpp: 在静态成员函数‘static void boost::python::detail::pickle_suite_registration::register_(Class_&, ...)’中:
boost_1_59_0/boost/python/object/pickle_support.hpp:110:31: 警告：typedef ‘error_type’ locally defined but not used [-Wunused-local-typedefs]
           Class_>::error_type error_type;
                               ^
In file included from boost_1_59_0/libs/python/src/object/pickle_support.cpp:6:0,
                 from pyprebuild.cpp:21:
boost_1_59_0/boost/python/make_function.hpp: 在函数‘boost::python::api::object boost::python::detail::make_function_aux(F, const CallPolicies&, const Sig&, const keyword_range&, NumKeywords)’中:
boost_1_59_0/boost/python/make_function.hpp:58:32: 警告：typedef ‘assertion’ locally defined but not used [-Wunused-local-typedefs]
           >::too_many_keywords assertion;
                                ^
</pre>

#### Avoid warning

避免这些gcc警告，有多种方式:
	
* 使用 gcc -Wno-* 选项，无视警告
* 更换较低版本的 g++
* 安装补丁
* 如果对以上方法都不满意，可以使用 deel.boost.python 代替 boost.python


#### Usage

1. 更改源码文件.

	在 C++ 代码文件中，将

	1.1 `#include <boost/python.hpp>` 更换为	`#include <deel.boost.python/boost/python.hpp>`

	1.2 `#include <libs/python/` 开头的行更换为 `#include <deel.boost.python/libs/python/`


2. 添加gcc编译选项.

	gcc 添加 `-I/path/to/deel.boost.python/../` 选项


deel.boost.python 依赖于boost库(推荐 boost-1.57.0以上) 和 python-dev



#### Amendment record

#####step 1. 
查找所有包含 	`#include <boost/python/` 、 `#include <boost/python.hpp>` 和 `#include <libs/python/` 的文件。
	
	$ grep -nr "#\s*include\s*<boost\/python" *
	$ grep -nr "#\s*include\s*<libs\/python\/" *
		
#####step 2. 
将 `#include <boost/python.hpp>` 替换为 `#include <deel.boost.python/revise/boost/python.hpp>`

<pre>$ REPLACE=deel.boost.python\\\/revise\\\/</pre>
	$ sed -i "s/\(#\s*include\s*<\)\(boost\/python.hpp\)/\1${REPLACE}\2/g" `grep -rl "#\s*include\s*<boost\/python.hpp>" *`



######step 3. 
将 `#include <boost/python/` 替换为 `#include <deel.boost.python/revise/boost/python/`
	
<pre>$ REPLACE=deel.boost.python\\\/revise\\\/</pre>
	$ sed -i "s/\(#\s*include\s*<\)\(boost\/python\/\)/\1${REPLACE}\2/g" `grep -rl "#\s*include\s*<boost\/python\/" *`

#####step 4. 
将 `#include <libs/python/` 替换为 `#include <deel.boost.python/revise/libs/python/` 
	
<pre>$ REPLACE=deel.boost.python\\\/revise\\\/</pre>
	$ sed -i "s/\(#\s*include\s*<\)\(libs\/python\/\)/\1${REPLACE}\2/g" `grep -rl "#\s*include\s*<libs\/python\/" *`

#####step 5.
受影响的文件[详情](./modified_files.txt)





