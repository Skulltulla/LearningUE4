# Animation | 0000

## SM_Cube

A two-meter cube was created that had no material and was imported into the project using Send to Unreal.

In Unreal, the mesh was automatically given a Material Slot and assigned **WorldGridMaterial**.

Collision was also automatically generated for the imported mesh.

## SM_Frustum

In Blender, the two-meter cube was modified to appear like a frustum by bringing four vertices closer together; and the entire cube
was rotated so the shorter end faces down the positive x-axis. Finally, if necessary, all of its transforms were applied using the Apply operation (CTRL A).

## SM_Frustum_Raised

Similar to SM_Frustum, but in Blender it was raised, such that the bottom rested on the origin. Similarly, all transforms were applied (CTRL A).

## SM_Frustum_AutoConvex

In Unreal, the SM_Frustum asset was duplicated and automatically generated collision was removed and then the Auto Convex Collision operation was used.

- Hull Count = 4
- Max Hull Verts = 16
- Hull Precision = 100,000

## BP_StaticMesh

Contains a Static Mesh Component and a Text Render Component. Instances of this may enable Simulate Physics on the Static Mesh Component.

## BP_AnimMesh

A child of BP_StaticMesh that adds rotation to the Static Mesh during the Tick event.

# Dev. Env.
- Blender 2.91.0
- UE 4.26.0
- Send to Unreal 1.6.3

