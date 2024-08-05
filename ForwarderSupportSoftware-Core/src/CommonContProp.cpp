#include "CommonContProp.h"

#include "curl/curl.h"

const std::string& CommonContProp::getContainerNumber() const
{
	return this->cntNumber;
}

const std::string& CommonContProp::getStatusDescription() const
{
	return this->statusDescription;
}

const std::string& CommonContProp::getLocation() const
{
	return this->location;
}

const std::string& CommonContProp::getTimeOfIssue() const
{
	return this->timeOfIssue;
}

const std::string& CommonContProp::getPodEta() const
{
	return this->podEta;
}

void CommonContProp::setContainerNumber(std::string cntNumber)
{
	this->cntNumber = cntNumber;
}

void CommonContProp::setStatusDescription(std::string statusDescription)
{
	this->statusDescription = statusDescription;
}

void CommonContProp::setLocation(std::string location)
{
	this->location = location;
}

void CommonContProp::setTimeOfIssue(std::string timeOfIssue)
{
	this->timeOfIssue = timeOfIssue;
}

void CommonContProp::setPodEta(std::string podEta)
{
	this->podEta = podEta;
}

// Callback function to write the data received from curl to a string
static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* s)
{
    size_t totalSize = size * nmemb;
    s->append((char*)contents, totalSize);
    return totalSize;
}

bool runCurlGetRequest(const std::string& url, std::string& responseData)
{
    CURL* curl;
    CURLcode res;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &responseData);

        // Perform the request
        res = curl_easy_perform(curl);

        // Check for errors
        if (res != CURLE_OK) {
            assert("curl_easy_perform() failed: " << curl_easy_strerror(res));
            curl_easy_cleanup(curl);
            return false;
        }

        // Clean up
        curl_easy_cleanup(curl);
    }
    return true;

}

bool runCurlPostRequest(const std::string& url, const std::string& postFields, std::string& responseData)
{
    CURL* curl;
    CURLcode res;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

        // Set the POST request with JSON data
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postFields.c_str());

        // Set headers
        struct curl_slist* headers = nullptr;
        headers = curl_slist_append(headers, "X-Requested-With: XMLHttpRequest");
        headers = curl_slist_append(headers, "Content-Type: application/json");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        // Write the response to a string
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &responseData);

        // Perform the request
        res = curl_easy_perform(curl);

        // Clean up
        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);

        // Check for errors
        if (res != CURLE_OK) {
            assert( "curl_easy_perform() failed: " << curl_easy_strerror(res) );
            return false;
        }
    }
    return true;
}
