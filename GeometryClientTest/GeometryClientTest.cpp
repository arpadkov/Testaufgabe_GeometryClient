#include "pch.h"
#include "CppUnitTest.h"
#include "../Point3D.cpp"
#include "../Vector3D.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

float relativeTolerance = 0.00001; // 0.001% -> used to compare points for equality

namespace GeometryClientTest
{
	TEST_CLASS(Geometry3DTest)
	{
	public:
		
		TEST_METHOD(Point3DEqualsTest)
		{
			Point3D point1 = Point3D(1.653, 1.982, 1.333);
			Point3D point2 = Point3D(1.653, 1.982, 1.333);
			Assert::IsTrue(point1.samePointAs(point2, relativeTolerance));

			Point3D point3 = Point3D(1.65300001, 1.982, 1.333);
			Point3D point4 = Point3D(1.653, 1.982, 1.333);
			Assert::IsTrue(point3.samePointAs(point4, relativeTolerance));
		}

		TEST_METHOD(Point3DNotEqualsTest)
		{
			Point3D point1 = Point3D(1.0001, 1.0, 1.0);
			Point3D point2 = Point3D(1.0, 1.0, 1.0);
			Assert::IsFalse(point1.samePointAs(point2, relativeTolerance));
		}

		TEST_METHOD(Vector3DEqualsTest)
		{
			Vector3D vector1 = Vector3D(1.653, 1.982, 1.333);
			Vector3D vector2 = Vector3D(1.653, 1.982, 1.333);
			Assert::IsTrue(vector1.sameVectorAs(vector2, relativeTolerance));

			Vector3D vector3 = Vector3D(1.65300001, 1.982, 1.333);
			Vector3D vector4 = Vector3D(1.653, 1.982, 1.333);
			Assert::IsTrue(vector3.sameVectorAs(vector4, relativeTolerance));
		}

		TEST_METHOD(Vector3DNotEqualsTest)
		{
			Vector3D vector1 = Vector3D(1.0001, 1.0, 1.0);
			Vector3D vector2 = Vector3D(1.0, 1.0, 1.0);
			Assert::IsFalse(vector1.sameVectorAs(vector2, relativeTolerance));
		}

		TEST_METHOD(Point3DOffsetTest)
		{
			// TODO: create some more complex points, also with negativ values

			Point3D originalPoint = Point3D(1.0, 1.0, 1.0);
			Vector3D offsetVector = Vector3D(1.0, 0.0, 0.0);

			Point3D* newPoint = originalPoint.offsetByVector(offsetVector);
			Point3D verifyPoint = Point3D(2.0, 1.0, 1.0);

			Assert::IsTrue(newPoint->samePointAs(verifyPoint, relativeTolerance));
		}

		TEST_METHOD(Vector3DUnitvectorTest)
		{
			// TODO: create some more complex vectors, also with negativ values

			Vector3D originalVector = Vector3D(1.0, 0.0, 0.0);
			Vector3D verifyVector = Vector3D(1.0, 0.0, 0.0);

			Vector3D unitVector = originalVector.getUnitVector();

			Assert::IsTrue(unitVector.sameVectorAs(verifyVector, relativeTolerance));
		}

		TEST_METHOD(Vector3DMultiplyTest)
		{
			Vector3D originalVector = Vector3D(1.0, 1.0, 1.0);
			Vector3D verifyVector = Vector3D(2.0, 2.0, 2.0);

			double factor = 2.0;
			Vector3D scaledVector = originalVector * factor;

			Assert::IsTrue(scaledVector.sameVectorAs(verifyVector, relativeTolerance));
		}

	};
}
