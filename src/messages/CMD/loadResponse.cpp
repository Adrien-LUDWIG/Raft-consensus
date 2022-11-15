#include "loadResponse.hh"

namespace MessageNS::CMD {
LoadResponse::LoadResponse(const uuids::uuid& fileUID, int leaderId,
                           bool success, int originId)
    : ResponseToClient(leaderId, success, Type::RESP_CMD_LOAD, originId) {
  m_fileUID = fileUID;
}

LoadResponse::LoadResponse(const json& data) : ResponseToClient(data) {
  std::string uuidStr = data["fileUID"];
  m_fileUID = uuids::uuid::from_string(uuidStr).value();
}

json LoadResponse::toJSON() const {
  json data = LoadResponse::toJSON();

  data["fileUID"] = uuids::to_string(m_fileUID);

  return data;
}
}  // namespace MessageNS::CMD