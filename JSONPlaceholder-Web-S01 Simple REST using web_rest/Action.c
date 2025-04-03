Action()
{

/*

Updated: 04.2025
Script created by Salvador Camacho

This script was created with best practices, so it is more resilient, such as:
* Transaction naming
* No add cookies
* No third party
* One validation per transaction
* Think times at the end of each transaction to better simulate user behavior

The script does REST calls using the LoadRunner web_rest function, it does 2 GETs, 1 POST, 1 PUT and 1 DELETE

Runtime Settings were set to log only on errors and generate snapshot on errors, think times 75% to 150%

This script has 5 transactions
JSONPlaceholder-Web-S01-01 Get Posts (GET)
JSONPlaceholder-Web-S01-02 Get Post By ID (G ET)
JSONPlaceholder-Web-S01-03 Create Post (POST)
JSONPlaceholder-Web-S01-04 Update Post (PUT)
JSONPlaceholder-Web-S01-05 Delete Post (DELETE)

 */

	web_set_sockets_option("SSL_VERSION", "AUTO");
	
	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=\"userId\":",
		LAST);

	web_reg_save_param_json(
		"ParamName=postIDs",
		"QueryString=$..id",
		"SelectAll=Yes",
		SEARCH_FILTERS,
		"Scope=BODY",
		LAST);

lr_start_transaction("JSONPlaceholder-Web-S01-01 Get Posts (GET)");

	web_rest("Get Posts",
		"URL=https://jsonplaceholder.typicode.com/posts",
		"Method=GET",
		"Snapshot=t918091.inf",
		HEADERS,
		"Name=Accept", "Value=*/*", ENDHEADER,
		"Name=Accept-Encoding", "Value=gzip, deflate", ENDHEADER,
		LAST);
		
lr_end_transaction("JSONPlaceholder-Web-S01-01 Get Posts (GET)", LR_AUTO);
	
	lr_think_time(10);
	
	
	// Random Value for productId
	lr_save_string(lr_paramarr_random("postIDs"),"randomPostID");

	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=\"userId\":",
		LAST);
	
lr_start_transaction("JSONPlaceholder-Web-S01-02 Get Post By ID (GET)");

	web_rest("Get Post",
		"URL=https://jsonplaceholder.typicode.com/posts/{randomPostID}",
		"Method=GET",
		"Snapshot=t386431.inf",
		HEADERS,
		"Name=Accept", "Value=*/*", ENDHEADER,
		"Name=Accept-Encoding", "Value=gzip, deflate", ENDHEADER,
		LAST);
		
lr_end_transaction("JSONPlaceholder-Web-S01-02 Get Post By ID (GET)", LR_AUTO);
	
	lr_think_time(10);
	
	
	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=\"id\":",
		LAST);
	
lr_start_transaction("JSONPlaceholder-Web-S01-03 Create Post (POST)");

	web_rest("Create Post",
		"URL=https://jsonplaceholder.typicode.com/posts",
		"Method=POST",
		"EncType=raw",
		"Snapshot=t890480.inf",
		"Body={\r\n"
		"\"title\": \"foo\",\r\n"
		"\"body\": \"bar\",\r\n"
		"\"userId\": \"1\"\r\n"
		"}",
		HEADERS,
		"Name=Accept", "Value=*/*", ENDHEADER,
		"Name=Accept-Encoding", "Value=gzip, deflate", ENDHEADER,
		"Name=Content-Type", "Value=application/json; charset=UTF-8", ENDHEADER,
		LAST);
	
lr_end_transaction("JSONPlaceholder-Web-S01-03 Create Post (POST)", LR_AUTO);
	
	lr_think_time(10);


	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=\"id\":",
		LAST);
	
lr_start_transaction("JSONPlaceholder-Web-S01-04 Update Post (PUT)");

	web_rest("Update Post",
		"URL=https://jsonplaceholder.typicode.com/posts/{randomPostID}",
		"Method=PUT",
		"EncType=raw",
		"Snapshot=t918091.inf",
		"Body={\r\n"
		"\"id\": \"{randomPostID}\",\r\n"
		"\"title\": \"foo\",\r\n"
		"\"body\": \"bar\",\r\n"
		"\"userId\": \"1\"\r\n"
		"}",
		HEADERS,
		"Name=Accept", "Value=*/*", ENDHEADER,
		"Name=Accept-Encoding", "Value=gzip, deflate", ENDHEADER,
		"Name=Content-Type", "Value=application/json; charset=UTF-8", ENDHEADER,
		LAST);
		
lr_end_transaction("JSONPlaceholder-Web-S01-04 Update Post (PUT)", LR_AUTO);
	
	lr_think_time(10);
	
	
	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text={}",
		LAST);
	
lr_start_transaction("JSONPlaceholder-Web-S01-05 Delete Post (DELETE)");

	web_rest("Delete Post",
		"URL=https://jsonplaceholder.typicode.com/posts/{randomPostID}",
		"Method=DELETE",
		"Snapshot=t918091.inf",
		HEADERS,
		"Name=Accept", "Value=*/*", ENDHEADER,
		"Name=Accept-Encoding", "Value=gzip, deflate", ENDHEADER,
		"Name=Content-Type", "Value=application/json; charset=UTF-8", ENDHEADER,
		LAST);
		
lr_end_transaction("JSONPlaceholder-Web-S01-05 Delete Post (DELETE)", LR_AUTO);
	
	lr_think_time(10);

	return 0;
}
