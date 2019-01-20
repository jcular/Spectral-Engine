#include "VertexData.h"

#include <algorithm>

namespace sp {
	VertexData::VertexData(
		float const * const dataArray, int const arraySize, unsigned int const * const elementIndices, int const indexCount, bool const uvCoords, bool const normalCoords) :
		dataArray{ new float[arraySize] },
		dataArraySize{ arraySize },
		elementIndices{ new unsigned int[indexCount] },
		indexCount{ indexCount },
		uvCoords { uvCoords },
		normalCoords{ normalCoords } {
		std::copy(dataArray, &dataArray[arraySize], this->dataArray);
		std::copy(elementIndices, &elementIndices[indexCount], this->elementIndices);
	}

	VertexData::VertexData(VertexData const & vertexData) :
		dataArray { new float[vertexData.dataArraySize] },
		dataArraySize{ vertexData.dataArraySize },
		elementIndices{ new unsigned int[vertexData.indexCount] },
		indexCount{ vertexData.indexCount },
		uvCoords{ vertexData.uvCoords },
		normalCoords{ vertexData.normalCoords } {
		std::copy(dataArray, &dataArray[vertexData.dataArraySize], this->dataArray);
		std::copy(elementIndices, &elementIndices[vertexData.indexCount], this->elementIndices);
	}

	VertexData::VertexData(VertexData && vertexData) :
		dataArray{ vertexData.dataArray },
		dataArraySize{ vertexData.dataArraySize },
		elementIndices{ vertexData.elementIndices },
		indexCount{ vertexData.indexCount },
		uvCoords{ vertexData.uvCoords },
		normalCoords{ vertexData.normalCoords } {
		float ** dataArrayNoConst = const_cast<float **>(&vertexData.dataArray);
		*dataArrayNoConst = nullptr;
		unsigned int ** indexArrayNoConst = const_cast<unsigned int **>(&vertexData.elementIndices);
		*indexArrayNoConst = nullptr;
	}

	VertexData::~VertexData() {
		delete[] this->dataArray;
		delete[] this->elementIndices;
	}

	int const VertexData::getStride() const {
		int stride = 3;

		if (uvCoords) {
			stride += 2;
		}

		if (normalCoords) {
			stride += 3;
		}

		return stride;
	}

	float const * const VertexData::getDataArray() const {
		return this->dataArray;
	}

	int const VertexData::getDataArraySize() const {
		return this->dataArraySize;
	}

	unsigned int const * const VertexData::getIndexArray() const {
		return this->elementIndices;
	}

	int const VertexData::getIndexCount() const {
		return this->indexCount;
	}

	bool const VertexData::hasUVCoords() const {
		return this->uvCoords;
	}

	bool const VertexData::hasNormalCoords() const {
		return this->normalCoords;
	}
}
