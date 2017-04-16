#include <string>
#include "include/jsonhttpreq.h"

JSONHTTPReq::JSONHTTPReq(){}
JSONHTTPReq::~JSONHTTPReq(){}

nlohmann::json JSONHTTPReq::getJSONResponse()
{
	nlohmann::json JSON;
	JSON = nlohmann::json::parse(getResponse().c_str());
	return JSON;
}
