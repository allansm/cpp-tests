#include <curl/curl.h>
#include <allansm/io.hpp>
#include <allansm/util.hpp>

int prev = 0;

int progress_func(void* ptr, double total, double current){
	int percent = (100/total)*current;
	if(percent-prev >=5){
		print("█");
		prev=percent;
	}

	fflush(stdout);

	return 0;	
}

main(){
	print("downloading : ");
	size_t (*tmp)(void *ptr, size_t size, size_t nmemb, std::string *s) = [](void *ptr, size_t size, size_t nmemb, std::string *s){
		s->append(static_cast<char *>(ptr), size*nmemb);
		return size*nmemb;
	};

	std::string link = "https://sample-videos.com/video123/mp4/720/big_buck_bunny_720p_30mb.mp4";

	CURL *curl;
	CURLcode res;
	std::string content;
	curl = curl_easy_init();

	curl_easy_setopt(curl, CURLOPT_URL,link.c_str());
	
	curl_easy_setopt(curl, CURLOPT_NOPROGRESS, FALSE);
	curl_easy_setopt(curl, CURLOPT_PROGRESSFUNCTION, progress_func);

	curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, tmp);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &content);
	
	res = curl_easy_perform(curl);

	char *ct;
      
	res = curl_easy_getinfo(curl, CURLINFO_CONTENT_TYPE, &ct);
	
	curl_easy_cleanup(curl);
}
