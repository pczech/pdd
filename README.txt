Hooks
-----
hook_action_info
hook_action_info_alter
hook_install
hook_menu
hook_menu_alter
hook_menu_link_alter
hook_node_insert
hook_node_load
hook_permission
hook_query_alter
hook_query_TAG_alter
hook_schema
hook_schema_alter
hook_trigger_info
hook_user_login
hook_uninstall

Form API
--------
drupal_get_form
form_set_error
system_settings_form

FORM_ID_submit
FORM_ID_validate

Field API
---------
field_create_field
field_create_instance
field_delete_field
field_delete_instance
field_info_field
field_info_instance

actions
-------
MODULE_FUNCNAME_action
MODULE_FUNCNAME_action_form
MODULE_FUNCNAME_action_submit
MODULE_FUNCNAME_action_validate

Generic
-------
drupal_anonymous_user
drupal_get_path
drupal_goto
drupal_set_title
drupal_write_record
module_invoke_all
node_type_get_types
variable_set
variable_get
variable_del
watchdog


PHP
---
empty
unset
is_numeric
is_int
intval
in_array
session_destroy


Database tables
---------------
actions
field_data_annotate
field_config_instance
menu_router
menu_links
node
variable


database API
------------
db_query
DatabaseStatementBase::fetchField

db_insert
InsertQuery::fields
InsertQuery::values
InsertQuery::execute

db_update
UpdateQuery::fields
UpdateQuery::condition
UpdateQuery::execute

db_delete
DeleteQuery::condition
DeleteQuery::execute

db_select
SelectQuery::fields
SelectQuery::condition
SelectQuery::execute
SelectQuery::range
SelectQuery::extend
SelectQuery::orderBy
SelectQuery::distinct

SelectQueryExtender::orderBy
SelectQueryExtender::limit

db_rename_table
db_add_field
db_drop_field
db_drop_index
db_query_temporary
db_set_active


hook_form_alter
