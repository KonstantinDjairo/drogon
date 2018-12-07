/**
 *
 *  DrTemplateBase.cc
 *  An Tao
 *  
 *  Copyright 2018, An Tao.  All rights reserved.
 *  https://github.com/an-tao/drogon
 *  Use of this source code is governed by a MIT license
 *  that can be found in the License file.
 *
 *  Drogon
 *
 */

#include <drogon/DrTemplateBase.h>
#include <drogon/DrClassMap.h>
#include <trantor/utils/Logger.h>
#include <memory>

using namespace drogon;

std::shared_ptr<DrTemplateBase> DrTemplateBase::newTemplate(std::string templateName)
{
    LOG_TRACE << "http view name=" << templateName;
    auto pos = templateName.find(".csp");
    if (pos != std::string::npos)
    {
        if (pos == templateName.length() - 4)
        {
            templateName = templateName.substr(0, pos);
        }
    }
    auto obj = std::shared_ptr<DrObjectBase>(drogon::DrClassMap::newObject(templateName));
    if (obj)
    {
        return std::dynamic_pointer_cast<DrTemplateBase>(obj);
    }
    return nullptr;
}
