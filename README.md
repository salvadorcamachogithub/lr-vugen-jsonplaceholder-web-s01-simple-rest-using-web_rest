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

This script has 5 transactions:  
JSONPlaceholder-Web-S01-01 Get Posts (GET)  
JSONPlaceholder-Web-S01-02 Get Post By ID (GET)  
JSONPlaceholder-Web-S01-03 Create Post (POST)  
JSONPlaceholder-Web-S01-04 Update Post (PUT)  
JSONPlaceholder-Web-S01-05 Delete Post (DELETE)