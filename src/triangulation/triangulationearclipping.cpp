#include "triangulationearclipping.h"

TriangulationEarClipping::TriangulationEarClipping() {}

struct VertexNode {
    CPoint p;
    int id;
};

bool isConcavePoint(const CPoint &p1, const CPoint &p2, const CPoint &p3)
{
    return CPoint::orientation(p1, p2, p3) != CPoint::OrientationTypes::left;
}

bool isEar(int vid,
           std::list<VertexNode>::iterator it,
           std::list<VertexNode> &vertexList,
           const std::unordered_map<int, std::list<VertexNode>::iterator> &idToIt,
           const std::unordered_set<int> &concaveSet)
{
    auto prev_it = it;

    if (prev_it == vertexList.begin())
        prev_it = std::prev(vertexList.end());
    else
        prev_it--;

    auto next_it = it;
    next_it++;

    if (next_it == vertexList.end())
        next_it = vertexList.begin();

    const CPoint &pPrev = prev_it->p;
    const CPoint &pCurr = it->p;
    const CPoint &pNext = next_it->p;

    if (isConcavePoint(pPrev, pCurr, pNext))
        return false;

    for (int cid : concaveSet) {
        if (cid == vid) continue;
        if (cid == prev_it->id || cid == next_it->id)
            continue;

        auto cit_lookup = idToIt.find(cid);
        if (cit_lookup == idToIt.end()) continue;
        if (CPoint::isPointInTriangle(cit_lookup->second->p, pPrev, pCurr, pNext))
            return false;
    }

    return true;
}

std::list<CPoint>::iterator TriangulationEarClipping::getPrev(std::list<CPoint>::iterator it_curr, std::list<CPoint> &vertex)
{

}

std::list<CPoint>::iterator TriangulationEarClipping::getNext(std::list<CPoint>::iterator it_curr, std::list<CPoint> &vertex)
{

}

std::vector<triangle> TriangulationEarClipping::EarClipping(std::vector<CPoint> polygon)
{
    std::vector<triangle> res;

    if (polygon.size() < 3) return res;
    if (polygon.size() == 3) {
        res.emplace_back(polygon[0], polygon[1], polygon[2]);
        return res;
    }

    std::list<VertexNode> vertexList;

    std::unordered_map<int, std::list<VertexNode>::iterator> idToIt;

    int idCounter = 0;
    for (const auto &p : polygon) {
        vertexList.push_back({p, idCounter});
        auto it = std::prev(vertexList.end());
        idToIt[idCounter] = it;
        idCounter++;
    }

    std::unordered_set<int> concaveSet;

    std::queue<int> earsQueue;
    std::unordered_set<int> earsSet;

    for (auto it = vertexList.begin(); it != vertexList.end(); ++it) {
        auto prev = (it == vertexList.begin()) ? std::prev(vertexList.end()) : std::prev(it);
        auto next = std::next(it);
        if (next == vertexList.end())
            next = vertexList.begin();

        if (isConcavePoint(prev->p, it->p, next->p)) {
            concaveSet.insert(it->id);
        }
    }

    for (auto it = vertexList.begin(); it != vertexList.end(); ++it) {
        if (isEar(it->id, it, vertexList, idToIt, concaveSet)) {
            earsQueue.push(it->id);
            earsSet.insert(it->id);
        }
    }

    int remaining = static_cast<int>(vertexList.size());

    while (!earsQueue.empty() && remaining > 2) {
        int earId = earsQueue.front();
        earsQueue.pop();

        auto itMap = idToIt.find(earId);
        if (itMap == idToIt.end()) {
            earsSet.erase(earId);
            continue;
        }

        auto earIt = itMap->second;
        if (!isEar(earId, earIt, vertexList, idToIt, concaveSet)) {
            earsSet.erase(earId);
            continue;
        }


        auto prevIt = (earIt == vertexList.begin()) ? std::prev(vertexList.end()) : std::prev(earIt);
        auto nextIt = std::next(earIt);
        if (nextIt == vertexList.end()) nextIt = vertexList.begin();

        res.emplace_back(prevIt->p, earIt->p, nextIt->p);

        earsSet.erase(earId);
        concaveSet.erase(earId);
        idToIt.erase(earId);
        vertexList.erase(earIt);
        remaining--;


        auto updateNeighbor = [&](std::list<VertexNode>::iterator neighborIt) {
            int nid = neighborIt->id;

            auto nPrev = (neighborIt == vertexList.begin()) ? std::prev(vertexList.end()) : std::prev(neighborIt);
            auto nNext = std::next(neighborIt);
            if (nNext == vertexList.end()) nNext = vertexList.begin();

            bool isNowConcave = isConcavePoint(nPrev->p, neighborIt->p, nNext->p);
            bool wasConcave = (concaveSet.find(nid) != concaveSet.end());

            if (wasConcave && !isNowConcave) {
                concaveSet.erase(nid);
            } else if (!wasConcave && isNowConcave) {
                concaveSet.insert(nid);
            }
            if (isEar(nid, neighborIt, vertexList, idToIt, concaveSet)) {
                if (earsSet.find(nid) == earsSet.end()) {
                    earsSet.insert(nid);
                    earsQueue.push(nid);
                }
            }
        };

        updateNeighbor(prevIt);
        updateNeighbor(nextIt);
    }

    return res;
}




