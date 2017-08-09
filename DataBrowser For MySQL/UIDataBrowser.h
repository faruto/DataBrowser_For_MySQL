/*
 * DataBrowser For MySQL UI
 * By WuyfCR7
*/
#ifndef __UI_DATA_BROWSER_MYSQL_H__
#define __UI_DATA_BROWSER_MYSQL_H__
#ifdef _MSC_VER > 1000
#pragma once
#endif
#include "UIConnectorInfo.h"
#include <boost\serialization\singleton.hpp>
#include <boost\noncopyable.hpp>
#include <FL\Fl_Tree.H>
#include <FL\fl_message.H>
#include <FL\Fl_Window.H>
#include <FL\Fl_Button.H>
#include <FL\Fl_Output.H>
#include <FL\Fl_Menu_Bar.H>
#include <FL\Fl_Menu_Button.H>
#include "FLTKOutputRowTable.h"


class UIDataBrowserForMySQL:public boost::noncopyable
{
private:
	typedef boost::serialization::singleton<UIDataBrowserForMySQL> DataBrowserForMySQLSingleton;
public:
	Fl_Window*           window_;
	Fl_Menu_Bar*         menu_;
	Fl_Tree*             tree_summary_;
	Fl_Menu_Button*      popupmenu_tree_;
	Fl_Output_Table_Row* table_browser_;
	Fl_Button*           button_first_page_;
	Fl_Button*           button_next_page_;
	Fl_Button*           button_prev_page_;
	Fl_Output*           output_from_text_;
	Fl_Output*           output_from_edit_;
	Fl_Output*           output_line_text_;
	Fl_Output*           output_line_edit_;
public:
	typedef boost::shared_ptr<boost::thread> ThreadPtr;
	MySQLClientManager mysql_manager_;
	std::vector<ThreadPtr> thread_manager_;
public:
	UIDataBrowserForMySQL();
	~UIDataBrowserForMySQL();

	void OnInitizeDialog();
	void OnInitizeCallBack();
	void show();
	void join();

	static UIDataBrowserForMySQL& GetInstance();

	// CallBack
	static void add_one_connector(Fl_Widget*, void*);
	static void update_all_connectors(Fl_Widget*, void*);
	static void update_this_connector(Fl_Widget*, void*);
	static void remove_all_connectors(Fl_Widget*, void*);
	static void remove_this_connector(Fl_Widget*, void*);
	static void connect_this_connector(Fl_Widget*, void*);
	static void query_this_data(Fl_Widget*, void*);
	static void dataquery_prev_page(Fl_Widget*, void*);
	static void dataquery_next_page(Fl_Widget*, void*);

	// ConnectInfo CallBack
	static void connect_info_return(Fl_Widget*, void*);
	static void connect_info_cancel(Fl_Widget*, void*);
};

/// ����TREE�ؼ�����ICON
void tool_renew_tree_all_icons(Fl_Tree*);

/// ����TREE�ؼ�����MYSQL��Connector��ICON
void tool_renew_tree_item_icons(Fl_Tree_Item*);

/// ���TREE�ؼ���һ��MYSQL��Connector
Fl_Tree_Item* tool_add_one_connector(UIDataBrowserForMySQL*, MySQLClientManager::MySQLConnectorManagerPtr);

/// ����TREE�ؼ�����MYSQL��Connector��Ϣ
void tool_update_tree_all_items(UIDataBrowserForMySQL*, bool);

/// ����TREE�ؼ�����MYSQL��Connector��Ϣ
void tool_update_tree_one_item(UIDataBrowserForMySQL*, std::string, bool);

/// ʹ������TREE�ؼ����ֲ���ʾ״̬
void tool_close_tree_all_child(Fl_Tree*);

/// ʹ��TREE�ؼ��µĵ���Connector���ֲ���ʾ״̬
void tool_close_tree_item_child(Fl_Tree_Item*);

/// ����TREE�ؼ���ȡ��ѯ���ݿ����Ϣ
bool tool_database_info_fromtree(UIDataBrowserForMySQL*, MYSQL**, std::string&, std::string&, std::string&);

/// �������ݿ�Ĳ�ѯ������ʾ��Table��
void tool_database_show_table(MYSQL*, std::string, std::string, std::string, int, int, UIDataBrowserForMySQL*);










#endif